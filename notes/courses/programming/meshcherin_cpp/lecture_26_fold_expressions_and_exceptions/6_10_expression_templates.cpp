#include <iostream>
#include <type_traits>
#include <cassert>
#include <array>


// we want to evaluate specific element of vector sum, but without evaluating entire sum 



template <typename E>
class VecExpression {
  public:
    static constexpr bool is_leaf = false;

    double operator[](size_t i) const {
        // Delegation to the actual expression type. This avoids dynamic polymorphism (a.k.a. virtual functions in C++)
        return static_cast<E const&>(*this)[i];
    }
    size_t size() const { return static_cast<E const&>(*this).size(); }
};

class Vec : public VecExpression<Vec> { // crtp
    std::array<double, 3> elems;

  public:
    static constexpr bool is_leaf = true;

    auto operator[](size_t i) const { return elems[i]; }
    auto &operator[](size_t i)      { return elems[i]; }
    size_t size()               const { return elems.size(); }

    // construct Vec using initializer list 
    Vec(std::initializer_list<double> init) {
        std::copy(init.begin(), init.end(), elems.begin());
    }

    // A Vec can be constructed from any VecExpression, forcing its evaluation.
    template <typename E>
    Vec(VecExpression<E> const& expr) {
        for (size_t i = 0; i != expr.size(); ++i) {
            elems[i] = expr[i];
        }
    }
};


template <typename E1, typename E2>
class VecSum : public VecExpression<VecSum<E1, E2> > { // crtp
  // cref if leaf, copy otherwise
  typename std::conditional<E1::is_leaf, const E1&, const E1>::type _u; // left side of expression
  typename std::conditional<E2::is_leaf, const E2&, const E2>::type _v; // right side of expression

  public:
    static constexpr bool is_leaf = false;

    VecSum(E1 const& u, E2 const& v) : _u(u), _v(v) {
        assert(u.size() == v.size());
    }
    decltype(auto) operator[](size_t i) const { return _u[i] + _v[i]; }
    size_t size()               const { return _v.size(); }
};
  
template <typename E1, typename E2>
VecSum<E1, E2>
operator+(VecExpression<E1> const& u, VecExpression<E2> const& v) {
   return VecSum<E1, E2>(*static_cast<const E1*>(&u), *static_cast<const E2*>(&v));
}


int main() {
	
	
    Vec v0 = {23.4,  12.5,  144.56};
    Vec v1 = {67.12, 34.8,  90.34};
    Vec v2 = {34.90, 111.9, 45.12};
    
    // Following assignment will call the ctor of Vec which accept type of 
    // `VecExpression<E> const&`. Then expand the loop body to 
    // a.elems[i] + b.elems[i] + c.elems[i]
    Vec sum_of_vec_type = v0 + v1 + v2; 

    for (size_t i = 0; i < sum_of_vec_type.size(); ++i)
        std::cout << sum_of_vec_type[i] << std::endl;

    // To avoid creating any extra storage, other than v0, v1, v2
    // one can do the following (Tested with C++11 on GCC 5.3.0)
    auto sum = v0 + v1 + v2;
    for (size_t i = 0; i < sum.size(); ++i)
        std::cout << sum[i] << std::endl;
    // Observe that in this case typeid(sum) will be VecSum<VecSum<Vec, Vec>, Vec>
    // and this chaining of operations can go on.
}
#include <iostream>
#include <cstring>
#include <algorithm>

class CowString {
	
    struct Buffer {
        char* data;
        size_t size;
        size_t refcount;

        Buffer(const char* str, size_t len) 
            : data(new char[len + 1]), size(len), refcount(1) {
            std::copy(str, str + len, data);
            data[len] = '\0';
        }

        ~Buffer() {
            delete[] data;
        }
    };

    Buffer* buffer;
	
	bool detach_buffer_on_access = true;

    // Ensure we have our own copy if shared
    void detach() {
        if (buffer && buffer->refcount > 1) {
            buffer->refcount--;
            buffer = new Buffer(buffer->data, buffer->size);
        }
    }

public:
    // Default constructor
    CowString() : buffer(nullptr) {}

    // Constructor from C-string
    CowString(const char* str) 
        : buffer(new Buffer(str, strlen(str))) {}

    // Copy constructor (shares buffer)
    CowString(const CowString& other) 
        : buffer(other.buffer) {
        if (buffer) buffer->refcount++;
    }

    // Destructor
    ~CowString() {
        if (buffer && --buffer->refcount == 0) {
            delete buffer;
        }
    }

    // Assignment operator
    CowString& operator=(const CowString& other) {
        if (this != &other) {
            if (buffer && --buffer->refcount == 0) {
                delete buffer;
            }
            buffer = other.buffer;
            if (buffer) buffer->refcount++;
        }
        return *this;
    }

	void set_detach_buffer_on_access( bool flag )
	{
		detach_buffer_on_access = flag;
	}


    // Non-const access - triggers copy if needed
    char& operator[]( size_t index )
	{
		if ( detach_buffer_on_access )
			detach();
        return buffer->data[index];
    }

    // Const access - no copy needed
    const char& operator[](size_t index) const {
        return buffer->data[index];
    }

    // Get C-string (const version)
    const char* c_str() const {
        return buffer ? buffer->data : "";
    }

    // Get current reference count (for demonstration)
    size_t refcount() const {
        return buffer ? buffer->refcount : 0;
    }

    // Get size
    size_t size() const {
        return buffer ? buffer->size : 0;
    }
};

int main() {
    std::cout << "=== COW String Demonstration ===\n";

    // Create original string
    CowString s1 = "Hello";
    std::cout << "s1: " << s1.c_str() 
              << " (refcount: " << s1.refcount() << ")\n";

    // Copy construction (shares buffer)
    CowString s2 = s1;
    std::cout << "After copy:\n";
    std::cout << "s1: " << s1.c_str() 
              << " (refcount: " << s1.refcount() << ")\n";
    std::cout << "s2: " << s2.c_str() 
              << " (refcount: " << s2.refcount() << ")\n";

    // Modify s2 (triggers copy)
    s2[0] = 'J';
    std::cout << "\nAfter modification:\n";
    std::cout << "s1: " << s1.c_str() 
              << " (refcount: " << s1.refcount() << ")\n";
    std::cout << "s2: " << s2.c_str() 
              << " (refcount: " << s2.refcount() << ")\n";

    // Assignment operator
    CowString s3;
    s3 = s1;
    std::cout << "\nAfter assignment:\n";
    std::cout << "s1: " << s1.c_str() 
              << " (refcount: " << s1.refcount() << ")\n";
    std::cout << "s3: " << s3.c_str() 
              << " (refcount: " << s3.refcount() << ")\n";


	s1.set_detach_buffer_on_access( false );
    // Const access doesn't trigger copy
    const char& c = s1[1];
    std::cout << "\nAfter const access:\n";
    std::cout << "s1: " << s1.c_str() 
              << " (refcount: " << s1.refcount() << ")\n";
    std::cout << "Second character: " << c << "\n";

    std::cout << "\n=== End of scope (destructors called) ===\n";
    return 0;
}
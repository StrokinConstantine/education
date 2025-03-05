vector<int> z2(string const &s) 
{
	vector<int> ret(s.size());
	for (int j = 1, l = 0, r = 0; j < s.size(); j++)
	{
		int p = j > r ? j : j+min(r-j+1, ret[j-l]);
		while (p < s.size() && s[p] == s[p-j])
			p++;
			ret[j] = p-j; 
			if (p > r)
			{
				l = j; r = p-1;
			}
		}
	return ret;
}
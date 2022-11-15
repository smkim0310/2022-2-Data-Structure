// two comparator functions
// The value returned indicates whether the element passed as first argument // is considered to go before the second in the specific ordering.
// more() and less() are equivalent to greater<int>() and less<int>() in STL.
bool more(int x, int y) { return x > y; } // for descending order
bool less(int x, int y) { return x < y; } // for ascending order
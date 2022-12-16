template <class IteratorT, class T> 
IteratorT Find( IteratorT begin, IteratorT end, const T& value ) 
{ 
    for ( ; begin != end ; begin++) 
        if (*begin == value) break;
    return begin; 
} 

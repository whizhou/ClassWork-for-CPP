template<typename Iterator>
void mySort(Iterator begin, Iterator end) {
//....
    for (Iterator i = begin; i != end; ++ i)
        for (Iterator j = begin; j != i; ++ j)
            if (*i < *j) {
                auto t = *i;
                *i = *j;
                *j = t;
            }
}
 
template<typename Iterator, typename Comp>
void mySort(Iterator begin, Iterator end, Comp cmp) {
//...用cmp来排序
    for (Iterator i = begin; i != end; ++ i)
        for (Iterator j = begin; j != i; ++ j)
            if (cmp(*i, *j)) {
                auto t = *i;
                *i = *j;
                *j = t;
            }
}
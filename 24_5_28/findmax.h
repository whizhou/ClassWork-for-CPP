template <typename T>
T Max(T *a, int n) {
    T maxNum = a[0];
    for (int i = 1; i < n; ++ i)
        if (a[i] > maxNum)
            maxNum = a[i];
    return maxNum;
}
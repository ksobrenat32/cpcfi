int getLestSignificantBit(int i) {
    return i & -i;
}
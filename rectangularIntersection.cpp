
auto intersect = [](auto &rect1, auto &rect2) {
    int x1, x2, y1, y2;
    tie(x1, y1, x2, y2) = rect1;
    int x3, x4, y3, y4;
    tie(x3, y3, x4, y4) = rect2;

    int x5 = max(x1, x3);
    int y5 = max(y1, y3);
    int x6 = min(x2, x4);
    int y6 = min(y2, y4);

    return tuple<int, int, int, int>{x5, y5, x6, y6};
};

auto check = [](auto &rect) {
    int x1, x2, y1, y2;
    tie(x1, y1, x2, y2) = rect;
    return (x1 <= x2 && y1 <= y2);
};
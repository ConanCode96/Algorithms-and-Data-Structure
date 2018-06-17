//Geometric;

    auto dist = [](pair<int, int> p1, pair<int, int> p2) {
        return hypotl(p1.X - p2.X, p1.Y - p2.Y);
    };

    auto ccw = [](pair<int, int> x1, pair<int, int> x2, pair<int, int> x3) {
        return (x1.X * (x2.Y - x3.Y) + x2.X * (x3.Y - x1.Y) + x3.X * (x1.Y - x2.Y)) / 2.0;
    };

    auto manhattan = [](pair<int, int> p1, pair<int, int> p2){
        return abs(p1.X - p2.X) + abs(p1.Y - p2.Y);
    };

struct obj{

    string x, y;
    bool operator==(const obj &o) const{
        return o.x == x && o.y == y;
    }

};

struct hasher
{
    std::size_t operator()(const obj &v) const
    {
        return hash<string>()(v.x) + hash<string>()(v.y);
    }
};

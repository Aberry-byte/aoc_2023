class Bag
{
private:
    int red;
    int green;
    int blue;
public:
    Bag(int num_of_red, int num_of_green, int num_of_blue);
    ~Bag();
    bool valid_pull(int num_of_red, int num_of_green, int num_of_blue);
};

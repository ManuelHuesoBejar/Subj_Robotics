template <typename N>
struct pose{
    pose(N x=0, N y=0, N z=0): px{x}, py{y}, pz{z} {};
    N px;
    N py;
    N pz;
};
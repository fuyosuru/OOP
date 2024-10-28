class Node{
    public:
        Node* next;
        double var;
        Node(double x);
};
class List{
    private:
        Node* head;
        unsigned int size;
    public:
        List();
        void Them(double x);
        void Xuat();
        bool Xoa(double x);
        void XoaHet(double x);
        void ThayDoi(int x,double y);
};
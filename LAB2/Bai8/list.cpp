#include<bits/stdc++.h>
#include "list.h"

Node::Node(double x)
{
    //Contructor của class Node.
    var=x;
    next=nullptr;
}

List::List()
{
    //Contructor của class List.
    head=nullptr;
    size=0;
}

void List::Them(double x)
{
    //Phương thức thêm một phần tử vào cuối list.
    //Đầu vào: giá trị muốn thêm vào.
    Node* newnode=new Node(x);
    if(head==nullptr)
        {
            head=newnode;
            size=1;
            return;
        }
    Node* cur=head;
    while(cur->next!=nullptr)
        cur=cur->next;
    cur->next=newnode;
    size++;
}

bool List::Xoa(double x)
{
    //Phương thức xoá một phần tử có giá trị mong muốn trong trong list.
    //Đầu vào: giá trị muốn xoá.
    Node* cur=head;
    Node* prev;
    if(cur==nullptr)
        return false;
    if(cur->var==x)
        {
            head=head->next;
            delete cur;
            return true;
        }
    while(cur!=nullptr && cur->var!=x)
        {
            prev=cur;
            cur=cur->next;
        }
    if(cur!=nullptr)
    {
        prev->next=cur->next;
        delete cur;
        size--;
        return true;
    }
    return false;
}

void List::XoaHet(double x)
{
    //Phương thức xoá các phần tử có giá trị mong muốn trong trong list.
    //Đầu vào: giá trị muốn xoá.
    while(Xoa(x));
}

void List::ThayDoi(int x,double y)
{
    //Phương thức xuất thay đổi số thứ x trong list thành y.
    //Đầu vào: vị trí muốn thay đổi và giá trị thay thế.
    int dem=0;
    Node* cur=head;
    while(dem<x && cur!=nullptr)
    {
        dem++;
        cur=cur->next;
    }
    if(dem==x && cur!=nullptr)
        cur->var=y;
}

void List::Xuat()
{
    //Phương thức xuất nội dung của list
    Node* cur=head;
    while(cur!=nullptr)
    {
        std::cout<<cur->var<<" ";
        cur=cur->next;
    }
    std::cout<<"\n";
}


#include <bits/stdc++.h>
using namespace std;

class ThoiGian{
private:
    int gio,phut,giay;

public:
    ThoiGian(int h=0,int m=0,int s=0): gio(h), phut(m), giay(s) {}

    ThoiGian& operator++()
    {
        giay++;
        if(giay==60)
        {
            giay=0;
            phut++;
            if(phut==60)
            {
                phut=0;
                gio++;
                if(gio==24) 
                    gio=0;
            }
        }
        return *this;
    }

    ThoiGian& operator++(int t)
    {
        ThoiGian temp=*this;
        giay++;
        if(giay==60)
        {
            giay=0;
            phut++;
            if(phut==60)
            {
                phut=0;
                gio++;
                if(gio==24) 
                    gio=0;
            }
        }
        return temp;
    }

    friend istream& operator>>(istream& is,ThoiGian& t)
    {
        is>>t.gio>>t.phut>>t.giay;
        return is;
    }

    friend ostream& operator<<(ostream& os,ThoiGian t)
    {
        os<<t.gio<<":"<<t.phut<<":"<<t.giay<<"\n";
        return os;
    }

};



int main()
{
    ThoiGian t;
    cout<<"Nhap thoi gian (hh:mm:ss): ";
    cin>>t;
    cout<<"Thoi gian da nhap la: "<<t;
    ++t;
    cout<<"Thoi gian sau khi tang 1 giay la: "<<t;
}






/*
\begin{table}[H]
\centering
\begin{tabularx}{\textwidth}{X|X|X}
\toprule
\textbf{Yếu tố} & \textbf{Người có điểm cao ở yếu tố này thường} & \textbf{Người có điểm thấp ở yếu tố này thường} \\
\midrule
\textbf{Sẵn sàng trải nghiệm (O)}\\\\Yếu tố Sẵn sàng trải nghiệm chỉ ra mức độ sẵn sàng tiếp nhận những cái mới, khả năng tuân thủ các quy định, luật lệ chung của một người.\\\\ Yếu tố Sẵn sàng trải nghiệm có 6 tiêu chí gồm: thích nghệ thuật, trải nghiệm cảm xúc, trải nghiệm hoạt động, ham hiểu biết, tự do, trí tưởng tượng. & Người có điểm cao ở yếu tố này thường là
người thích những ý tưởng mới, thích hiểu biết nhiều lĩnh vực nhưng đồng thời cũng thích tự do, không thích bị ràng buộc... & Người có điểm thấp ở yếu tố này thường khá bảo thủ, khó tiếp nhận những ý tưởng mới, lạ. Họ thích sự ổn định, quen thuộc và thực tế. \\
\midrule
\textbf{Tự chủ tận tâm (C)}\\\\ Yếu tố Tự chủ chỉ ra khả năng chịu áp lực, sự nỗ lực, kiên trì của một người.\\\\ Yếu tố Tự chủ được chia ra thành 6 tiêu chí nhỏ gồm: tính trật tự, kỷ luật, tự tin, trách nhiệm, nỗ lực, thận trọng. & Chăm chỉ, có khả năng chịu áp lực tốt, trung thành với tổ chức & Dễ bỏ cuộc, khả năng chịu áp lực, tuân thủ kỷ luật của tổ chức kém \\
\midrule
\textbf{Hướng ngoại (E)}\\\\ Yếu tố Hướng ngoại chỉ ra khả năng giao tiếp, thái độ nhiệt tình trong công việc cũng như mức độ thích tạo sự ảnh hưởng của một người.\\\\ Yếu tố Hướng ngoại có 6 tiêu chí nhỏ gồm: thích tạo ảnh hưởng, quảng giao, tích cực vận động, tìm kiêm sự hưng phấn, thân thiện, cảm xúc tích cực. & Nhiệt tình, năng động, giao tiếp tốt, thích thể hiện bản thân & Ngại giao tiếp, không thích sự nổi bật, thích được làm việc độc lập \\
\midrule
\textbf{Hòa đồng dễ chịu (A)}\\\\ Yếu tố Hoà đồng chỉ ra mức độ hoà hợp, sự quan tâm và chấp nhận sự khác biệt của một người.\\\\ Hòa đồng có 6 tiêu chí nhỏ gồm: tin tưởng, hợp tác, thành thực, vị tha, khiêm tốn, nhân hậu. & Thân thiện, cởi mở, đồng cảm với mọi người & Đặt lợi ích của bản thân lên trên, ít đồng cảm, chia sẻ với đồng nghiệp, có tính cạnh tranh cao \\
\midrule
\textbf{Bất ổn cảm xúc (N)}\\\\ Yếu tố Bất ổn cảm xúc chỉ ra khả năng kiểm soát cảm xúc, chịu áp lực, ứng phó với căng thăng của một người.\\\\ Yếu tố Bất ổn cảm xúc có 6 tiêu chí tâm lý gồm: trầm cảm, tự ti, sống bản năng, dễ bị tổn thương, lo âu, giận dữ. & Có các cảm xúc tiêu cực như: lo lắng, bực bội, tự ti, yếu đuối và khả năng chịu áp lực kém & Kiểm soát được cảm xúc, ứng phó với căng thẳng tốt, ít bị bên ngoài ảnh hưởng đến tâm trạng của bản thân \\
\bottomrule
\end{tabularx}
\caption{Mô tả các yếu tố tính cách}
\end{table}
*/
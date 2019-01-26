#include <bits/stdc++.h> 

using namespace std;

const int MAXN = 10005;
struct bign  
{  
    int len, s[MAXN];  
    bign ()  //��ʼ��
    {  
        memset(s, 0, sizeof(s));  
        len = 1;  
    }  
    bign (int num) { *this = num; }  
    bign (const char *num) { *this = num; }  //��thisָ��ָ��ǰ�ַ���
    bign operator = (const int num)  
    {  
        char s[MAXN];  
        sprintf(s, "%d", num);  //sprintf����������ӳ���ַ�����
        *this = s;  
        return *this;  //�ٽ��ַ���ת�������ַ���ת���ĺ�����
    }  
    bign operator = (const char *num)  
    {  
        for(int i = 0; num[i] == '0'; num++) ;  //ȥǰ��0  
        len = strlen(num);  
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0'; //���Ŵ�
        return *this;
    }  
    bign operator + (const bign &b) const //��Ӧλ��ӣ���Ϊ��
    {  
        bign c;  
        c.len = 0;  
        for(int i = 0, g = 0; g || i < max(len, b.len); i++)  
        {  
            int x = g;  
            if(i < len) x += s[i];  
            if(i < b.len) x += b.s[i];  
            c.s[c.len++] = x % 10;  //���ڼӷ���λ
            g = x / 10;  
        }  
        return c;  
    }  
    bign operator += (const bign &b)  //��������˵��������������������
    {  
        *this = *this + b;  
        return *this;  
    }  
    void clean()  //���ڽ����������㲻��ȷ������ĳ��ȣ��ȴ����֮Ȼ���ٲ�
    {  
        while(len > 1 && !s[len-1]) len--;  //��λ���֡�0����ɾ���ò��ֳ���
    }   
    bign operator * (const bign &b) //�˷�������������ʽ���ٽ���ʽ�е���תΪ���󣬼��ɿ������㷨��
    {  
        bign c;  
        c.len = len + b.len;  
        for(int i = 0; i < len; i++)  
        {  
            for(int j = 0; j < b.len; j++)  
            {  
                c.s[i+j] += s[i] * b.s[j];//�����и���ʽ��һ��
            }  
        }  
        for(int i = 0; i < c.len; i++) //���ڽ�λ����ӷ���ͬ 
        {  
            c.s[i+1] += c.s[i]/10;
            c.s[i] %= 10;
        }  
        c.clean();  //���ǹ���λ����a+b�ĳ��Ⱥͣ������ܱ���С��1*1 = 1��
        return c;  
    }  
    bign operator *= (const bign &b)  
    {  
        *this = *this * b;  
        return *this;  
    }  
    bign operator - (const bign &b)  //��Ӧλ������ӷ��Ľ�λ��Ϊ��1
    {  //�����Ǹ���
        bign c;  
        c.len = 0;  
        for(int i = 0, g = 0; i < len; i++)  
        {  
            int x = s[i] - g;  
            if(i < b.len) x -= b.s[i];  //���ܳ��Ȳ���
            if(x >= 0) g = 0;  //�Ƿ�������λ��1
            else  
            {  
                g = 1;  
                x += 10;  
            }  
            c.s[c.len++] = x;  
        }  
        c.clean();  
        return c;   
    }  
    bign operator -= (const bign &b)  
    {  
        *this = *this - b;  
        return *this;  
    }  
    bign operator / (const bign &b)  //���ó��Ǽ��ı��ʣ���ͣ�ؼ���ֱ��С�ڱ�����
    {  
        bign c, f = 0; //���ܻ���ʹ�ü���ʱ���ָ߾������� 
        for(int i = len-1; i >= 0; i--)  //����˳�򣬴����λ��ʼ
        {  
            f = f*10;  //����λ��ʣ�ൽ��һλ*10
            f.s[0] = s[i];  //���ϵ�ǰλ
            while(f >= b)  
            {  
                f -= b;  
                c.s[i]++;  
            }  
        }  
        c.len = len;  //���λ
        c.clean();  
        return c;  
    }  
    bign operator /= (const bign &b)  
    {  
        *this  = *this / b;  
        return *this;  
    }  
    bign operator % (const bign &b)  //ȡģ���ǳ���ʣ�µ�
    {  
        bign r = *this / b;  
        r = *this - r*b;  
        r.clean();
        return r;  
    }  
    bign operator %= (const bign &b)  
    {  
        *this = *this % b;  
        return *this;  
    }  
    bool operator < (const bign &b) //�ַ����Ƚ�ԭ�� 
    {  
        if(len != b.len) return len < b.len;  
        for(int i = len-1; i != -1; i--)  
        {  
            if(s[i] != b.s[i]) return s[i] < b.s[i];  
        }  
        return false;  
    }  
    bool operator > (const bign &b)  //ͬ��
    {  
        if(len != b.len) return len > b.len;  
        for(int i = len-1; i != -1; i--)  
        {  
            if(s[i] != b.s[i]) return s[i] > b.s[i];  
        }  
        return false;  
    }  
    bool operator == (const bign &b)  
    {  
        return !(*this > b) && !(*this < b);  
    }  
    bool operator != (const bign &b)  
    {  
        return !(*this == b);  
    }  
    bool operator <= (const bign &b)  
    {  
        return *this < b || *this == b;  
    }  
    bool operator >= (const bign &b)  
    {  
        return *this > b || *this == b;  
    }  
    string str() const  //�����ת��Ϊ�ַ��������������
    {  
        string res = "";  
        for(int i = 0; i < len; i++) res = char(s[i]+'0')+res;  
        return res;  
    }  
};  

istream& operator >> (istream &in, bign &x) //���������� 
{  
    string s;  
    in >> s;  
    x = s.c_str();  //stringת��Ϊchar[]
    return in;  
}  

ostream& operator << (ostream &out, const bign &x)  //���������
{  
    out << x.str();  
    return out;  
}
bign n,ans=1;
int main()
{
	//freopen
    cin>>n;
    bign tmp=1,t2=1,t3=1;
    for(bign i=1;i<=n/2;i=i+1){
    	t2=1;t3=1;
    	for(tmp=n-i+1;tmp>=n-i-i+2;tmp=tmp-1) t2*=tmp;
    	for(tmp=i;tmp>=1;tmp=tmp-1) t3*=tmp;
    	ans+=t2/t3;
    	ans%=1000007;
	}
	ans%=1000007;
    cout<<ans<<endl;
    return 0;
}

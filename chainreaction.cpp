//170110013
#include <simplecpp>
struct cs101
{
    static int a[9][6],p;
    cs101()
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<6;j++)
                a[i][j]=0;
    }
    void check(int x, int y)
    {
        if(x>0&&x<8&&y>0&&y<5&&(abs(a[x][y])==4||abs(a[x][y])==5||abs(a[x][y])==6||abs(a[x][y])==7))
        {
            if(p%2==1&&a[x][y]>0)
            {
                a[x][y]-=4;
                a[x-1][y]=abs(a[x-1][y])+1 ;
                a[x][y-1]=abs(a[x][y-1])+1 ;
                a[x+1][y]=abs(a[x+1][y])+1 ;
                a[x][y+1]=abs(a[x][y+1])+1 ;
            }
            else if(p%2==0&&a[x][y]<0)
            {
                a[x][y]+=4;
                a[x-1][y]=-abs(a[x-1][y])-1 ;
                a[x][y-1]=-abs(a[x][y-1])-1 ;
                a[x+1][y]=-abs(a[x+1][y])-1 ;
                a[x][y+1]=-abs(a[x][y+1])-1 ;
            }
            check(x,y+1) ;
            check(x+1,y) ;
            check(x,y-1) ;
            check(x-1,y) ;
        }
        else if((x==0||x==8||y==0||y==5)&&(abs(a[x][y])==3||abs(a[x][y])==4||abs(a[x][y])==5))
        {
            if(p%2==1&&a[x][y]>0)
            {
                a[x][y]-=3;//Night One.
                if(x!=0) a[x-1][y]=abs(a[x-1][y])+1 ;
                if(y!=0) a[x][y-1]=abs(a[x][y-1])+1 ;
                if(x!=8) a[x+1][y]=abs(a[x+1][y])+1 ;
                if(y!=5)a[x][y+1]=abs(a[x][y+1])+1 ;
            }
            else if(p%2==0&&a[x][y]<0)
            {
                a[x][y]+=3;
                if(x!=0) a[x-1][y]=-abs(a[x-1][y])-1 ;
                if(y!=0) a[x][y-1]=-abs(a[x][y-1])-1 ;
                if(x!=8) a[x+1][y]=-abs(a[x+1][y])-1 ;
                if(y!=5)a[x][y+1]=-abs(a[x][y+1])-1 ;
            }
            check(x,y+1) ;
            check(x+1,y) ;
            check(x,y-1) ;
            check(x-1,y) ;
        }
        else if(((x==0&&y==0)||(x==8&&y==0)||(x==8&&y==5)||(x==0&&y==5))&&(abs(a[x][y])==2||abs(a[x][y])==3))
        {
            if(p%2==1&&a[x][y]>0)
            {
                a[x][y]-=2;//Night One.
                if(x!=0) a[x-1][y]=abs(a[x-1][y])+1 ;
                if(y!=0) a[x][y-1]=abs(a[x][y-1])+1 ;
                if(x!=8) a[x+1][y]=abs(a[x+1][y])+1 ;
                if(y!=5)a[x][y+1]=abs(a[x][y+1])+1 ;
            }
            else if(p%2==0&&a[x][y]<0)
            {
                a[x][y]+=2;
                if(x!=0) a[x-1][y]=-abs(a[x-1][y])-1 ;
                if(y!=0) a[x][y-1]=-abs(a[x][y-1])-1 ;
                if(x!=8) a[x+1][y]=-abs(a[x+1][y])-1 ;
                if(y!=5)a[x][y+1]=-abs(a[x][y+1])-1 ;
            }
            check(x,y+1) ;
            check(x+1,y) ;
            check(x,y-1) ;
            check(x-1,y) ;
        }
        
    }
    void abeen(int x,int y)
    {
        if(x>8||x<0||y>5||y<0)
            return;
        if(p%2==1)
        {
            if(a[x][y]<0){cout<<"Illegal move"<<endl;p--;return;}
            else
                a[x][y]++;
        }
        else
        {
            if(a[x][y]>0){cout<<"Illegal move"<<endl;p--;return;}
            else
                a[x][y]--;
        }
        check(x,y);
        for(int i =0; i<9;i++){
            for(int j=0;j<6;j++)
                cout<<a[i][j]<<" ";
        cout<<endl;
    }
};
int cs101::a[9][6]={{0,0}};
int cs101::p=0;
int main ()
{
    cs101 obj;
    int x,y;
    int s=0;;
    while(true)
    {
        s=0;
        cin>>x;
        if(x==-1){break;}
        if(x>8||x<0)
        {cout<<"Illegal move"<<endl;continue;}
        cin>>y;
        if(y>5||y<0)
        {
            cout<<"Illegal move"<<endl;
            continue;
        }
        cs101::p++;
        obj.abeen(x,y);cout<<endl;
        if(cs101::p>2)
            for(int i =0;i<9;i++)
                for(int j=0;j<6;j++)
                    s=s+cs101::a[i][j];
        if(cs101::p==abs(s))
            break;
    }
}

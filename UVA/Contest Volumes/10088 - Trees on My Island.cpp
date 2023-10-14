#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    int x,y;
    
    point(){
    }
    
    point(const int _x, const int _y){
        x=_x; y=_y;
    }
    
    point operator - (const point &p) const{
        return point(x-p.x,y-p.y);
    }
};

long long AreaBy2(const vector<point> &poly){
    int n=poly.size();
    long long S=0;
    
    for(int i=1;i<n;i++) S+=(long long)poly[i].x*(poly[i+1<n? i+1:i+1-n].y-poly[i-1].y);
    S+=(long long)poly[0].x*(poly[1].y-poly[n-1].y);
    
    if(S<0) return -S;
    return S;
}

int IntegerPointsOnSegment(const point &P1, const point &P2){
    point P=P1-P2;
    P.x=abs(P.x); P.y=abs(P.y);
    
    if(P.x==0) return P.y-1;
    if(P.y==0) return P.x-1;
    return (__gcd(P.x,P.y))-1;
}

int main(){
    int N,x,y;
    long long S,B,I;
    vector<point> poly;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        poly.clear();
        
        for(int i=0;i<N;i++){
            scanf("%d %d",&x,&y);
            poly.push_back(point(x,y));
        }
        
        S=AreaBy2(poly); B=N;
        for(int i=0,j=N-1;i<N;j=i++) B+=IntegerPointsOnSegment(poly[j],poly[i]);
        
        printf("%lld\n",(S-B+2)>>1);
    }
    
    return 0;
}

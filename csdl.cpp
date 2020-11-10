#include<iostream>
#include<math.h>
/* bai toan tim thuoc tinh bao dong */
using namespace std;
struct qe
{
	string h;
};
struct  ff
{
	int d;
	int c;
	string dau[100];
	string cuoi[100];
};
struct qq
{
	int w;
	string sa[100];
};
void ganqq(qq &q, qq qz)
		{
			q.w=qz.w;
			for (int i=0;i<q.w;i++)
			q.sa[i]=qz.sa[i];
		}
void xuat(qq q)
		{
			cout<<"{";
			for (int i=0;i<q.w;i++)
			{
					cout<<q.sa[i];
					if(i<q.w-1)
					cout<<",";	
			}
			cout<<"}";
		}
void t2(qq &q,string d)
{
	q.w=0;
	int l=1;
	for (int i=1;i<d.length();i++)
	{
		if(d[i]==',')
		{
			q.sa[q.w]=d.substr(l,i-l);
			l=i+1;
			q.w++;
		}
		if(i==d.length()-1)
		{
			q.sa[q.w]=d.substr(l,i-l);
			q.w++;
		}
	}
}
void tach(ff &a, string t)
{
	int r=0;
	a.d=0;
	a.c=0;
	int s=t.find('-->',0)-2;
	int k=s+3;
	for(int i=0;i<s;i++)
	{
		if(t[i]==',')
		{
			a.dau[a.d]=t.substr(r,i-r);
			a.d++;
			r=i+1;
		}
		if(i==s-1)
			{
				a.dau[a.d]=t.substr(r,i-r+1);
				a.d++;
			}
	}
	for(int j=s+3;j<t.length();j++)
	{
		if(t[j]==',')
		{
			a.cuoi[a.c]=t.substr(k,j-k);
			a.c++;
			k=j+1;
		}
		if(j==t.length()-1)
			{
				a.cuoi[a.c]=t.substr(k,j-k+1);
				a.c++;
			}
	}
}
int hople(qq q, ff f)
{
	int n=0,k=0;
	for (int i=0;i<f.d;i++)
	for (int j=0;j<q.w;j++)
	{
		if(f.dau[i]==q.sa[j])
		n++;
	}
	for (int i=0;i<f.c;i++)
	for (int j=0;j<q.w;j++)
	{

		if(q.sa[j]==f.cuoi[i])
		k++;
	}
	if(k==f.c&n==f.d)
	return 1;
	return 0;
}
int c1(ff f, qq q)
{
	int n=0;
	for (int i=0;i<f.d;i++)
	for (int j=0;j<q.w;j++)
	if(f.dau[i]==q.sa[j])
	n++;
	return n;
}
void cong(qq &q, qq q1, qq q2)
{
		int z=0;
		q.w=q1.w+q2.w;
		for (int i=0;i<q1.w;i++)
		q.sa[i]=q1.sa[i];
		for (int j=q1.w;j<q.w;j++)
		{
			q.sa[j]=q2.sa[z];
			z++;
		}
}
int c2(ff f,qq q)
{
	int k=0;
	for (int i=0;i<f.c;i++)
	for (int j=0;j<q.w;j++)
	if(f.cuoi[i]==q.sa[j])
	k++;
	return k;
}
		int check(ff f[100],qq q, int s)
			{
					int n=0,k=0;
					for(int i=0;i<s;i++)
					{
						n=c1(f[i],q);
						k=c2(f[i],q);
						
						if(n==f[i].d&&k!=f[i].c)
						return 1;
					}
					return 0;
			}
		void gan(string a, qq &q)
		{
			int k=0;
			for(int i=0;i<q.w;i++)
			if(a!=q.sa[i])
			k++;
			if(k==q.w)
			{
				q.sa[q.w]=a;
				q.w++;
			}
		}
		void thu(string a, qq &q)
		{
			q.sa[q.w]=a;
			q.w++;
		}
		void them(ff f, qq &q)
		{
				int k=0;
				for (int i=0;i<f.d;i++)
					for (int j=0;j<q.w;j++)
					if(f.dau[i]==q.sa[j])
					k++;
				if(k==f.d)
				for(int y=0;y<f.c;y++)
					gan(f.cuoi[y],q);
		}
		void baodong(ff f[100],qq x,qq &a,int s)
		{
			a.w=x.w;
			for(int i=0;i<x.w;i++)	
				a.sa[i]=x.sa[i];    
			while(check(f,a,s)==1)
			for (int i=0;i<s;i++)		
			them(f[i],a);                                               
		}
void tcuoi(ff ut,qq &q)
{
	q.w=ut.c;
	for (int i=0;i<q.w;i++)
	{
		q.sa[i]=ut.cuoi[i];
	}
}
void tdau(ff ut,qq &q)
{
	q.w=ut.d;
	for (int i=0;i<q.w;i++)
	{
		q.sa[i]=ut.dau[i];
	}
}
int bang(qq q1,qq q2)
		{
			int k=0;
			if(q1.w!=q2.w)
				return 0;
			for(int i=0;i<q2.w;i++)
			for(int j=0;j<q2.w;j++)
				if(q1.sa[i]==q2.sa[j])
				k++;
			if(k==q1.w)
	 		return 1;
			else 
			return 0;
		}
int lon(qq q, qq y)
{
	int v=0;
	for(int i=0;i<q.w;i++)
	for(int j=0;j<y.w;j++)
	if(q.sa[i]==y.sa[j])
	{
		v++;
	}
	if(q.w>y.w&&v==y.w)
	return 1;
	if(v==q.w&&v==y.w)
	return 1;
	return 0;
}
int thuoc(string a, qq q)
{
	int o=0;
	for (int i=0;i<q.w;i++)
		{
			if(a==q.sa[i])
			return 1;
		}
			return 0;
}
int thuoc2(qq a, qq b)
{
	int l=0,k=0;
	for (int i=0;i<a.w;i++)
	for (int j=0;j<b.w;j++)
			{
				if(a.sa[i]==b.sa[j])
				l++;
			}
	if(l==a.w)
	return 1;
	return 0;
}
int thuoc3(string a, qq q, qq ds[1000],int u)
{
	qq tr;
	tr.w=q.w+1;
	for (int i=0;i<q.w;i++)
	tr.sa[i]=q.sa[i];
	tr.sa[q.w]=a;
	
	for(int z=0;z<u;z++)
	if(bang(tr,ds[z])==1)
	return 1;
	return 0;
}
int thuoc4( qq q, qq t)
{
	int u=0;
	for (int i=0;i<q.w;i++)
	for (int j=0;j<t.w;j++)
	{
		if(q.sa[i]==t.sa[j])
		u++;
	}
	if(u==q.w)
	return 1;
	return 0;
}
int thuoc5(string a, qq ql)
	{
		for (int i=0;i<ql.w;i++)
		if(a==ql.sa[i])
		return 0;
		return 1;
	}
int thuoc6(qq q, qq index[1000],int iu)
	{
		for(int u=0;u<iu;u++)
		if(bang(q,index[u]))
		return 1;
		return 0;
	}
int thuoc7(qq q, qq a)
{
	int g=0;
	for(int i=0;i<q.w;i++)
	for(int j=0;j<a.w;j++)
	if(q.sa[i]==a.sa[j])
	g++;
	if(g==q.w)
	return 1;
	return 0;
}
int thuoc8(ff f,qq index[100],int iu)
{
	int c=0,d=0;
	qq q;
	tdau(f,q);
	for(int i=0;i<iu;i++)
	{
		if(lon(q,index[i])==1)
		c++;	
	}
	if(c>0)
	return 1;
	return 0;
}
void tkcd(qq &kcd,qq &m,qq q,ff f[100], int s)
		{
			int k=0,n=0;
			kcd.w=0;
			m.w=0;
			for(int i=0;i<q.w;i++)
			{
				for(int u=0;u<s;u++)
				{
							for (int j=0;j<f[u].d;j++)
							{
								if(q.sa[i]==f[u].dau[j])
								k++;
							}
							for(int z=0;z<f[u].c;z++)
							{
								if(q.sa[i]==f[u].cuoi[z])
								n++;
							}	
				}
				if(k>0&&n==0)
				{
					thu(q.sa[i],kcd);
				}
						
				if(k>0&&n>0)
				{
					thu(q.sa[i],m);
				}
				if(k==0&&n==0)
				{
					thu(q.sa[i],kcd);
				}
				k=0;n=0; 
			}
		}
	void cc(string a, qq q, qq &h)
	{
		h.w=q.w+1;	
		for(int i=0;i<q.w;i++)
		h.sa[i]=q.sa[i];
		h.sa[h.w-1]=a;
		
	}
	int ch(int n, int l)
	{
		if(n>l)
		return 0;
		int k=l-n;
		int s=1,b=1,o=1;
		for (int i=1;i<=l;i++)
			b=b*i;
		for (int j=1;j<=n;j++)
			s=s*j;
		for (int u=1;u<=k;u++)
			o=o*u;
		return (b/(s*o));
	}
	void doi(qq &q, qq qo)
		{
			q.w=qo.w;
			for(int i=0;i<q.w;i++)
			q.sa[i]=qo.sa[i];
		}
	
	void kt(qq q,qq h[1000],int a1,int a2, int &u)
	{				
			
									for (int i=a1;i<a2;i++)	
									{
										for (int m=0;m<q.w;m++)	
										{
										
										if(thuoc(q.sa[m],h[i])==0&&thuoc3(q.sa[m],h[i],h,u)==0)
												{
													cc(q.sa[m],h[i],h[u]);
													u++;											
												}
										}
												
	}
}
int ckt(qq q,qq gs[1000], int &c)
	{
		int a1=0, a2=0,a3=0;
		
		for (int j=0;j<q.w;j++)
		{
			gs[j].w=1;
			gs[j].sa[0]=q.sa[j];
			c++;
		}
		for (int i=2;i<q.w;i++)
		{
					a2=c;
					a1=c-ch(i-1,q.w);
					kt(q,gs,a1,a2,c);	
		}	
		return 0;
	}
void thay(qq &q, qq&c)
{
	
}
void xoa(qq q,qq tr[1000],int z)
{
	for(int i=0;i<z;i++)
	{
		if(thuoc4(q,tr[i])==1)
		tr[i].w=0;
	}
}
void khoa( qq q, qq Q, qq tr[1000],ff f[100], int z,int s, qq index[100], int &iu)
{
	iu=0;
	qq zi;
	zi.w=0;
	qq ue;
	ue.w=0;
		for(int i=0;i<z;i++)
		if(tr[i].w!=0)
		{
			cong(ue,q,tr[i]);	
			baodong(f,ue,zi,s);
			if(bang(zi,Q))
			{	
				xuat(ue);
				cout<<"la khoa "<<endl;
				doi(index[iu],ue);
				iu++;
				xoa(tr[i],tr,z);
			}
		}
}
void loc(qq &q)
{
	qq z;
	z.w=0;
	for (int i=0;i<q.w;i++)
	{
		if(thuoc(q.sa[i],z)==0)
		{
				z.sa[z.w]=q.sa[i];
				z.w++;
		}
	}
	doi(q,z);
}
int sss(ff ut, qq q)
{
	int c=0;
	for(int i=0;i<ut.d;i++)
	for (int j=0;j<q.w;j++)
	{
		if(ut.dau[i]==q.sa[j])
		c++;
	}
	if(c==q.w)
	return 1;
	return 0;
}
void ttkk(qq &q, qq Q,qq ml[100], int ui)
{
	int pot=0;
	q.w=0;
	for (int i=0;i<Q.w;i++)
	{
		for(int k=0;k<ui;k++)
		if(thuoc(Q.sa[i],ml[k])==0)
		pot++;
		if(pot==ui)
		{
			q.sa[q.w]=Q.sa[i];
			q.w++;
		}
		pot=0;
	}
}
int special(ff f, qq index2, qq index3, qq index[100],int iu)
{
	int a=0,b=0;
	qq d,c;
	tdau(f,d);
	tcuoi(f,c);
		if(bang(d,index3)==0)
		if(thuoc7(d,index3)==1&&thuoc6(d,index,iu)==0)
		if(thuoc7(c,index2)==1)
		return 0;
		
		return 1;
}
void timch(qq &index3, qq index[1000], int iu)
{
	index3.w=0;
	for (int i=0;i<iu;i++)
	for (int j=0;j<index[i].w;j++)
	{
		index3.sa[index3.w]=index[i].sa[j];
		index3.w++;
	}
	loc(index3);
}
int ttd(ff f, qq index2)
{
	qq d,c;
	tdau(f,d);
	tcuoi(f,c);
	if(thuoc7(d,index2)&&thuoc7(c,index2))
	return 0; 
	return 1;
}
void qwr2(ff ut[100],int s, qq index[100], int &iu, qq Q, qq index2, qq index3)
{
	int a=0;
	int x=0,y=0;
	qq phu;
	qq zx,lk;
	for(int i=0;i<s;i++)
	if(special(ut[i],index2,index3,index,iu)==0)
	{
		y++;
	}
	if(y>0)
	a=0;
	else
	a=2;
	if(a==2)
	{
		int u=0;
		for(int z=0;z<s;z++)
		{
			if(ttd(ut[z],index2)==1)
			x++;
			if(x==s)
			a=3;
		}
	}

	if(a==3)
	{
		int lk=0;
		for (int i=0;i<s;i++)
		if(thuoc8(ut[i],index,iu)==1)
		lk++;
		if(lk==s)
		a=4;
	}
	if(a==0)
	cout<<" DC1";
	if(a==2)
	cout<<" DC2";
	if(a==3)
	cout<<"DC3";
	if(a==4)
	cout<<" BCK";
}
int main()
{
		qq Q;
		cout << " Nhap vao ten luoc do quan he ";
		string a, q;
		cin >>a;
		int s;
		cout << " Nhap vao luoc do qua he "<<a<< "\n co dang (A,B,C) \n";
		cout <<a<<"=";cin>>q;
		t2(Q,q);
		cout<< " nhap vao so PTH:";
		cin>>s;
		qe f[s];
		ff ut[s];
		cout<<" nhap vao cac PTH co dang A,C-->B,E \n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
		for(int i=0;i<s;i++)
		{
			cout<<"f"<<i+1<<":";
			cin>>f[i].h; 
			tach(ut[i],f[i].h);
			while (hople(Q,ut[i])==0)
			{
					cout<<"nhap lai f"<<i+1<<":";
					cin>>f[i].h; 
					tach(ut[i],f[i].h);
			}
		}	
		

	for (int i=0;i<s;i++)
	tach(ut[i],f[i].h);
	qq tr[1000];
		int z=0;
		qq kcd;
		qq bd;
		qq mk;
		qq index[100];
		int iu=0;
		tkcd(kcd,mk,Q,ut,s);
		
		baodong(ut,kcd,bd,s);
		if(bang(bd,Q)==1)
		{
			cout<<"Z=";
			xuat(kcd);
			cout<<" la khoa chi dinh "<<endl;
			doi(index[0],kcd);
			iu++;
		}
		else 
		{
			xuat(kcd);
			cout<<" ko phai la khoa chinh"<<endl;
			ckt(mk,tr,z);
			khoa(kcd,Q,tr,ut,z,s, index,iu);	
		}
		qq index2;
		qq index3;
	 	ttkk(index2,Q,index,iu);
	 	timch(index3,index,iu);
	 	cout<<endl;
	 	cout<<"dang chuan:";
		qwr2(ut,s,index,iu,Q,index2,index3);
		cout<<endl;
		cout <<" nhap thuoc tinh can tim bao dong co dang (A,B), X=";
		string x;
		cin>>x;
		qq Xo;
		t2(Xo,x);
		while(thuoc4(Xo,Q)==0)
		{
			cout<<"nhap lai, X=";
			cin>>x;
			t2(Xo,x);
		}
		while (check(ut,Xo,s)==1)
		for (int i=0;i<s;i++)		
		them(ut[i],Xo);										
		cout<<"day la bao dong cua thuoc tinh X: X+={";
		for(int i=0;i<Xo.w;i++)
		{
			cout<<Xo.sa[i];
			if(i<Xo.w-1)
			cout<<",";
		}		
		cout<<"}";
		int ct=0, T=0;
		cout<<"\n Press 1 to countinue, any key to end:";
		cin>>ct;
		if(ct==1)
		{
			while(ct==1)
			{
				T++;
					cout <<" nhap thuoc tinh can tim bao dong co dang (A,B), X=";
					string x;
					cin>>x;
					qq Xo;
					t2(Xo,x);
					while (check(ut,Xo,s)==1)
						for (int i=0;i<s;i++)
							them(ut[i],Xo);		
					cout<<"day la bao dong cua thuoc tinh X: X+"<<T<<"={";
					for(int i=0;i<Xo.w;i++)
					{
						cout<<Xo.sa[i];
						if(i<Xo.w-1)
						cout<<",";
					}		
				cout<<"}";
				cout<<"\n nhan 1 de tiep tuc tim bao dang, nhan phim bat ki der ket thuc";
				cin>>ct;	
			}
		}
}
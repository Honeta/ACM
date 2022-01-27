#include<cstdio>
#include<vector>
#include<cstring>
#define N 10001
#define inf 0x7fffffff
using namespace std;
template<typename T>

class FiboHeap {

 public:

  FiboHeap() : min_(nullptr), size_(0) {}

  ~FiboHeap() {Destroy(min_);}

  bool empty() const {return size_ == 0;}

  size_t size() const {return size_;}

  void push(const T &val) {Insert(new Node(val));}

  void pop() {DeleteMin();}

  const T top() const {return min_->val_;}

  void clear() {

    size_ = 0;

    Destroy(min_);

  }

 private:

  struct Node {

    Node() : deg_(0), child_(nullptr), left_(nullptr), right_(nullptr) {}

    explicit Node(T val) : val_(val), deg_(0), child_(nullptr), left_(nullptr), right_(nullptr) {}

    T val_;

    size_t deg_;

    Node *child_, *left_, *right_;

  };

  Node *min_;

  size_t size_;

  void Insert(Node *temp) {

    ++size_;

    if (!min_) {

      min_ = temp;

      min_->left_ = temp;

      min_->right_ = temp;

      return;

    }

    min_->right_->left_ = temp;

    temp->right_ = min_->right_;

    temp->left_ = min_;

    min_->right_ = temp;

    if (temp->val_ < min_->val_)

      min_ = temp;

  }

  void DeleteMin() {

    if (!min_) return;

    --size_;

    if (!size_) {

      delete min_;

      min_ = nullptr;

      return;

    }

    Node *temp = min_;

    min_ = temp->right_;

    T val = temp->right_->val_;

    for (Node *cur = temp->right_; cur != temp; cur = cur->right_) {

      if (cur->val_ < val) {

        val = cur->val_;

        min_ = cur;

      }

    }

    temp->left_->right_ = temp->right_;

    temp->right_->left_ = temp->left_;

    if (temp->child_) {

      Insert(temp->child_);

      for (Node *cur = temp->child_->right_; cur != temp->child_; cur = cur->right_)

        Insert(cur);

    }

    delete temp;

    Node **last = new Node *[size_];

    for (Node *cur = min_; cur != min_; cur = cur->right_) {

      while (last[cur->deg_] && last[cur->deg_] != cur) {

        Node *temp = last[cur->deg_];

        last[cur->deg_] = 0;

        if (cur->val_ > temp->val_) {

          cur->left_->right_ = cur->right_;

          cur->right_->left_ = cur->left_;

          temp->deg_++;

          if (temp->child_) {

            temp->child_->right_->left_ = cur;

            temp->child_->right_ = cur;

          } else {

            temp->child_ = cur;

          }

          cur = temp;

        } else {

          temp->left_->right_ = temp->right_;

          temp->right_->left_ = temp->left_;

          cur->deg_++;

          if(cur->child_) {

            cur->child_->right_->left_ = temp;

            cur->child_->right_ = temp;

          } else {

            cur->child_ = temp;

          }          

        }

      }

      last[cur->deg_] = cur;

    }

    delete []last;

  }

  void Destroy(Node *cur) {

    if (!cur) return;

    Destroy(cur->child_);

    cur->child_ = nullptr;

    Node *pointer = cur->right_;

    cur->left_->right_ = cur->right_;

    cur->right_->left_ = cur->left_;

    delete cur;

    if (pointer != cur)

      Destroy(pointer);

  }

  void swap(FiboHeap<T> &other) noexcept {

    Node *min = min_;

    size_t size = size_;

    min_ = other.min_;

    other.min_ = min;

    size_ = other.size_;

    other.size_ = size;

  }

};
struct point{int p,dis;};
struct edge{int to,w;};
vector<edge>v[N];
FiboHeap<point>q;
int n,m,b,t,l,r,mid,ans=inf,t1,t2,t3,d[N],f[N];
bool inq[N];
bool operator<(point x,point y)
{return x.dis==y.dis?x.p>y.p:x.dis>y.dis;}
bool operator>(point x,point y)
{return x.dis==y.dis?x.p<y.p:x.dis<y.dis;}
int main()
{
  scanf("%d%d%d",&n,&m,&b);
  for(int i=1;i<=n;i++)
    {
      scanf("%d",&f[i]);
      r=f[i]>r?f[i]:r;
    }
  for(int i=1;i<=m;i++)
    {
      scanf("%d%d%d",&t1,&t2,&t3);
      v[t1].push_back({t2,t3});
      v[t2].push_back({t1,t3});
    }
  l=f[1]>f[n]?f[1]:f[n];
  r=r<l?l:r;
  while(l<=r)
    {
      mid=l+r>>1;
      memset(d,0x3f,sizeof(d));
      for(int i=1;i<=n;i++)inq[i]=f[i]>mid?1:0;
      d[1]=0;
      q.push({1,0});
      while(q.size())
	{
	  t=q.top().p;
	  q.pop();
	  if(inq[t])continue;
	  inq[t]=1;
	  for(int i=0;i<v[t].size();i++)
	    {
	      if(d[v[t][i].to]>d[t]+v[t][i].w)
		{
		  d[v[t][i].to]=d[t]+v[t][i].w;
		  q.push({v[t][i].to,d[v[t][i].to]});
		}
	    }
	}
      if(d[n]>=b)
	{
	  l=mid+1;
	  continue;
	}
      r=mid-1;
      ans=mid<ans?mid:ans;
    }
  if(ans==inf)printf("AFK");
  else printf("%d",ans);
  return 0;
}
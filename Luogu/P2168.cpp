#include<iostream>
using namespace std;
typedef long long ll;
template<typename T>
class FiboHeap {
 public:
  FiboHeap() : min_(nullptr), size_(0) {}
  bool empty() const {return size_ == 0;}
  size_t size() const {return size_;}
  void push(const T &val) {Insert(new Node(val));}
  void pop() {DeleteMin();}
  const T top() const {return min_->val_;}
  void clear() {}
 private:
  struct Node {
    Node() : val_(0), deg_(0), child_(nullptr), left_(nullptr), right_(nullptr) {}
    Node(T val) : val_(val), deg_(0), child_(nullptr), left_(nullptr), right_(nullptr) {}
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
    delete temp, &temp;
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
        delete &temp;
      }
      last[cur->deg_] = cur;
    }
    delete[] last;
  }
  void swap(FiboHeap<T> &other) noexcept {
    Node *min = min_;
    size_t size = size_;
    min_ = other.min_;
    other.min_ = min;
    size_ = other.size_;
    other.size_ = size;
    delete &min, &size;
  }
};
struct node{
    ll w,h;
    node(ll ww,ll hh)
    {
        w=ww;
        h=hh;
    }
};
FiboHeap<node> q;
ll temp,maxh,ans;
int n,k,cnt;
bool operator<(node x,node y)
{
    if(x.w!=y.w)return x.w>y.w;
    return x.h>y.h;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        q.push(node(temp,1));
    }
    if((n-1)%(k-1))cnt=k-1-(n-1)%(k-1);
    for(int i=1;i<=cnt;i++)q.push(node(0,1));
    cnt+=n;
    while(cnt>1)
    {
        temp=maxh=0;
        for(int i=1;i<=k;i++)
        {
            temp+=q.top().w;
            maxh=max(maxh,q.top().h);
            q.pop();
        }
        ans+=temp;
        q.push(node(temp,maxh+1));
        cnt-=k-1;
    }
    cout<<ans<<endl<<q.top().h-1;	
    return 0;
}
#include<cstdio>
#include<vector>
#include<algorithm>
#define maxn 100005
#define inf 1000000009
using namespace std;
template<typename T>

class Llrbt {

 public:   

  Llrbt() : root_(nullptr), size_(0), end_(this, nullptr) {}

  ~Llrbt() {Destroy(root_);}

  bool empty() const {return size_ == 0;}

  size_t size() const {return size_;}

  void insert(const T &val) {root_ = Insert(root_, val);}

  size_t erase(const T &val) {

    if (!Find(root_, val))   

      return 0;

    root_ = Delete(root_, val);

    return 1;

  }

  size_t count(const T &val) {return Find(root_, val) != nullptr;}

  void clear() {

    size_ = 0;

    Destroy(root_);

  }

  class iterator;

  iterator lower_bound(const T &);

  iterator upper_bound(const T &);

  iterator below_bound(const T &);

  iterator find(const T &);

  iterator begin();

  iterator end();

 private:

  static const bool RED = 0, BLACK = 1;

  struct Node {

    Node() : color_(BLACK), lchild_(nullptr), rchild_(nullptr), it_(nullptr) {}

    explicit Node(bool color, T val) : color_(color), val_(val), lchild_(nullptr), rchild_(nullptr), it_(nullptr) {}

    bool color_;

    T val_;

    Node *lchild_, *rchild_;

    iterator *it_;

  };

  Node *root_;

  size_t size_;

  Node *Insert(Node *cur, T val) {

    if (!cur) {

      cur = new Node(RED, val);

      size_++;

      cur->it_ = new iterator(this, cur);

      return cur;

    }

    if (cur == root_) cur->color_ = BLACK;

    if (cur->val_ == val)

      return cur;

    else if (cur->val_ < val)

      cur->rchild_ = Insert(cur->rchild_, val);

    else

      cur->lchild_ = Insert(cur->lchild_, val);

    cur = FixUp(cur);

    return cur;

  }

  Node *Delete(Node *cur, T val) {

    if (!cur) return nullptr;

    if (cur->val_ > val) {

      if (cur->lchild_->color_ == BLACK && cur->lchild_->lchild_->color_ == BLACK)

        cur = MoveRedLeft(cur);

      cur->lchild_ = Delete(cur->lchild_, val);

    } else {

      if (cur->lchild_ && cur->lchild_->color_ == RED)

        cur = RightRotate(cur);

      if (cur->val_ == val && !(cur->rchild_)) {

        size_--;

        delete cur->it_;

        delete cur;

        return nullptr;

      }        

      if (cur->rchild_ && cur->rchild_->color_ == BLACK && cur->rchild_->lchild_ && cur->rchild_->lchild_->color_ == BLACK)

        cur = MoveRedRight(cur);

      if (cur->val_ == val) {

        cur->val_ = GetMin(cur->rchild_)->val_;

        cur->rchild_ = DeleteMin(cur->rchild_);

        size_--;

      } else {

        cur->rchild_ = Delete(cur->rchild_, val);

      }

    }

    cur = FixUp(cur);

    return cur; 

  }

  void Destroy(Node *cur) {

    if (!cur) return;

    Destroy(cur->lchild_);

    Destroy(cur->rchild_);

    delete cur->it_;

    delete cur;

  }

  Node *Find(Node *cur, T val) {

    if (!cur) return nullptr;

    if (cur->val_ > val)

      return Find(cur->lchild_, val);

    else if (cur->val_ < val)

      return Find(cur->rchild_, val);

    else

      return cur;

  }

  Node *ColorFlip(Node *cur) {

    cur->rchild_->color_ ^= 1;

    cur->rchild_->color_ ^= 1;

    cur->color_ ^= 1;

    return cur;

  }

  Node *LeftRotate(Node *cur) {

    Node *rchild = cur->rchild_;

    cur->rchild_ = rchild->lchild_;

    rchild->lchild_ = cur;

    rchild->color_ = cur->color_;

    cur->color_ = RED;

    return rchild;

  }

  Node *RightRotate(Node *cur) {

    Node *lchild = cur->lchild_;

    cur->lchild_ = lchild->rchild_;

    lchild->rchild_ = cur;

    lchild->color_ = cur->color_;

    cur->color_ = RED;

    return lchild;

  }

  Node *DeleteMin(Node *cur) {

    if (!(cur->lchild_)) {

      delete cur->it_;

      delete cur;

      return nullptr;

    }

    if (cur->lchild_->color_ == BLACK && cur->lchild_->lchild_ && cur->lchild_->lchild_->color_ == BLACK)

      cur = MoveRedLeft(cur);      

    Node *lchild = DeleteMin(cur->lchild_);

    if (!lchild) {

      cur->lchild_ = nullptr;

    } else {

      cur->lchild_ = lchild;

    }

    cur = FixUp(cur);

    return cur;

  }

  Node *MoveRedRight(Node *cur) {

    ColorFlip(cur);

    if (cur->lchild_->lchild_ && cur->lchild_->lchild_->color_ == RED) {

      cur = RightRotate(cur);

      cur = ColorFlip(cur);

    }

    return cur;

  }

  Node *MoveRedLeft(Node *cur) {

    ColorFlip(cur);

    if (cur->rchild_->lchild_ && cur->rchild_->lchild_->color_ == RED) {

      cur->rchild_ = RightRotate(cur->rchild_);

      cur = LeftRotate(cur);

      cur = ColorFlip(cur);

    }

    return cur;

  }

  Node *FixUp(Node *cur) {

    if (cur->rchild_ && cur->rchild_->color_ == RED) 

      cur = LeftRotate(cur);

    if (cur->lchild_ && cur->lchild_->color_ == RED && cur->lchild_->lchild_ && cur->lchild_->lchild_->color_ == RED)

      cur = RightRotate(cur);

    if (cur->lchild_ && cur->lchild_->color_ == RED && cur->rchild_ && cur->rchild_->color_ == RED)

      cur = ColorFlip(cur);

    return cur;

  }

  Node *GetMin(Node *cur) {

    if (!cur) return nullptr;

    while (cur->lchild_)

      cur = cur->lchild_;

    return cur;

  }

  Node *GetMax(Node *cur) {

    if (!cur) return nullptr;

    while (cur->rchild_)

      cur = cur->rchild_;

    return cur;

  }

  Node *GetFront(Node *cur, T val) {

    if (!cur) return nullptr;

    if (cur->val_ < val) {

      if (!cur->rchild_)

        return cur;

      Node *pointer = GetFront(cur->rchild_, val);

      if(!pointer) pointer = cur;

      return pointer;

    } else {

      return GetFront(cur->lchild_, val);

    }      

  }

  Node *GetBack(Node *cur, T val) {

    if (!cur) return nullptr;

    if (cur->val_ > val) {

      if (!cur->lchild_)

        return cur;

      Node *pointer = GetBack(cur->lchild_, val);

      if(!pointer) pointer = cur;

      return pointer;

    } else {

      return GetBack(cur->rchild_, val);

    }      

  }

  iterator end_;

};

template<class T>

class Llrbt<T>::iterator {

 public:

  iterator() : this_(nullptr), pointer_(nullptr) {}

  explicit iterator(Llrbt<T> *father, Node *pointer) : this_(father), pointer_(pointer) {}

  T operator*() {return pointer_->val_;}

  iterator& operator++() {

    *this = this_->upper_bound(pointer_->val_);

    return *this;

  }

  iterator operator++(int) {

    iterator temp = *this;

    *this = this_->upper_bound(pointer_->val_);

    return temp;

  }

  iterator& operator--() {

    if(*this == this_->end_)

      this->pointer_ = this_->GetMax(this_->root_);

    else

      *this = this_->below_bound(pointer_->val_);

    return *this;

  }

  iterator operator--(int) {

    iterator temp = *this;

    if(*this == this_->end_)

      this->pointer_ = this_->GetMax(this_->root_);

    else

      *this = this_->below_bound(pointer_->val_);

    return temp;

  }

  iterator& operator=(const iterator &it) {

    this_ = it.this_;

    pointer_ = it.pointer_;

    return *this;

  }

  bool operator==(const iterator &it) {

    return this_ == it.this_ && pointer_ == it.pointer_;

  }

  bool operator!=(const iterator &it) {

    return this_ != it.this_ || pointer_ |= it.pointer_;

  }

 private:

  Llrbt<T> *this_;

  Node *pointer_;

};

template<class T>

typename Llrbt<T>::iterator Llrbt<T>::lower_bound(const T &val) {

  Node *pointer = Find(root_, val);

  if(!pointer) return upper_bound(val);

  return *(pointer->it_);

}

template<class T>

typename Llrbt<T>::iterator Llrbt<T>::upper_bound(const T &val) {

  Node *pointer = GetBack(root_, val);

  if(!pointer) return end_;

  return *(pointer->it_);

}

template<class T>

typename Llrbt<T>::iterator Llrbt<T>::below_bound(const T &val) {

  Node *pointer = GetFront(root_, val);

  if(!pointer) return end_;

  return *(pointer->it_);

}

template<class T>

typename Llrbt<T>::iterator Llrbt<T>::find(const T &val) {

  Node* pointer = Find(root_, val);

  if(!pointer) return end_;

  return *(pointer->it_);

}

template<class T>

typename Llrbt<T>::iterator Llrbt<T>::begin() {

  if(!root_) return end_;

  Node *pointer = GetMin(root_);

  return *(pointer->it_);

}

template<class T>

typename Llrbt<T>::iterator Llrbt<T>::end() {return end_;}
struct edge{
  int to,w;
};
struct point{
  int p,dis;
};
vector<edge>road[maxn];
Llrbt<point>undone;
int n,m,s,t1,t2,t3,d[maxn];
bool operator<(point x,point y)
{
  if(x.dis==y.dis)return x.p<y.p;
  return x.dis<y.dis;
}
bool operator>(point x,point y)
{
  if(x.dis==y.dis)return x.p>y.p;
  return x.dis>y.dis;
}
bool operator==(point x,point y)
{
  return x.p==y.p && x.dis==y.dis;
}
int main()
{
  scanf("%d%d%d",&n,&m,&s);
  for(int i=1;i<=m;i++)
    {
      scanf("%d%d%d",&t1,&t2,&t3);
      road[t1].push_back({t2,t3});
    }
  d[s]=0;
  undone.insert({s,0});
  for(int i=1;i<=n;i++)
    {
      if(i==s)continue;
      d[i]=inf;
      undone.insert({i,inf});
    }
  while(!undone.empty())
    {
      int now=(*undone.begin()).p;
      for(int i=0;i<road[now].size();i++)
	{
	  if(undone.find({road[now][i].to,d[road[now][i].to]})==undone.end())
        continue;
	  if(d[road[now][i].to]>d[now]+road[now][i].w)
	    {
	      undone.erase({road[now][i].to,d[road[now][i].to]});
	      d[road[now][i].to]=d[now]+road[now][i].w;
	      undone.insert({road[now][i].to,d[road[now][i].to]});
	    }
	}
      undone.erase({now,d[now]});
    }
  for(int i=1;i<=n;i++)printf("%d ",d[i]);
  return 0;
}	
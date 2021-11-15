#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <functional>

using namespace std;

template<typename T>
class bin_tree
{
private:
    class tree_node
    {
    private:
        T value;
        tree_node *right;
        tree_node *left;
    public:
        friend class bin_tree<T>;
        tree_node()
        {
            value = 0;
            right = nullptr;
            left = nullptr;
        }
        tree_node(T m_value):value(m_value){}
        ~tree_node()
        {
            delete[]right;
            delete[]left;
        }
    };
    tree_node *root;
public:
    bin_tree()
    {
        root = nullptr;
    }
    ~bin_tree()
    {
        delete[]root;
    }

    bool empty(){return root == nullptr;}

    class iterator
    {
        friend class bin_tree<T>;
    private:
        tree_node*node;
    public:
        iterator()
        {
            node = nullptr;
        }
        iterator(tree_node*nd)
        {
            node=nd;
        }
        iterator& operator=(const iterator &it)
        {
            node = it.node;
            return *this;
        }
        bool operator==(const iterator&it)
        {
            return(node==it.node);
        }
        T& operator*()
        {
            return node->value;
        }
    };



    void add(T new_el)
    {
        tree_node *add_node=new tree_node(new_el);
        if (empty())
            root=add_node;
        else
            while(1)
            {
                tree_node*temp=root;
                if (add_node->value>temp->value)
                {
                    if (!(temp->right))
                    {
                        temp->right=add_node;
                        break;
                    }
                    else
                        temp=temp->right;
                }
                if (add_node->value<temp->value)
                {
                    if (!(temp->left))
                    {
                        temp->left=add_node;
                        break;
                    }
                    else
                        temp=temp->left;
                }
                if (add_node->value==temp->value)
                {
                    break;
                }
            }
    }

    void erase(bin_tree<T>::iterator elem)
    {
        if(!(empty()))
        {
            tree_node *dr1=root,*dr2=nullptr,*dr3=nullptr;
            while(1)
            {
                if (!(*elem==dr1->value))
                {
                    dr2=dr1;
                    if(*elem>dr1->value)
                        dr1=dr1->right;
                    else
                        dr1=dr1->left;
                }
                else
                    break;
            }
            if (dr1 == root)
            {
                if (dr1->left)
                {
                    dr2 = dr1->left;
                    while (dr2->right != nullptr)
                        dr2 = dr2->right;
                    dr2->right = dr1->right;
                }
                else
                    dr1->left = dr1->right;
                root = dr1->left;
                //delete[]dr1;
                return;
            }
            if (dr1->right)
            {
                if (dr1->left)
                {
                    dr3 = dr1->left;
                    while (dr3->right != nullptr)
                        dr3 = dr3->right;
                    dr3->right = dr1->right;
                    if (dr2->right == dr1)
                        dr2->right = dr1->left;
                    if (dr2->left == dr1)
                        dr2->left = dr1->left;
                    //delete[]dr1;
                    return;
                }
                else
                {
                    if (dr2->right == dr1)
                        dr2->right = dr1->right;
                    if (dr2->left == dr1)
                        dr2->left = dr1->right;
                    //delete[]dr1;
                    return;
                }
            }
            else
            {
                if (dr1->left)
                {
                    if (dr2->right == dr1)
                        dr2->right = dr1->left;
                    if (dr2->left == dr1)
                        dr2->left = dr1->left;
                    //delete[]dr1;
                    return;
                }
                else
                {
                    if (dr2->right == dr1)
                        dr2->right = nullptr;
                    if (dr2->left == dr1)
                        dr2->left = nullptr;
                    //delete[]dr1;
                    return;
                }
            }
        }
    }

    iterator find(T elem)
    {
        bin_tree<T>::iterator it;
        it.node=nullptr;
        find_help(root,it,elem);
        return it;
    }

    void show()
    {
        showm(root);
    }
private:
    void showm(tree_node *h)
    {
        if(h)
        {
            if(h->left) showm(h->left);
            std::cout << h->value;
            if(h->right) showm(h->right);
        }
    }

    void find_help(tree_node *h,bin_tree<T>::iterator &u,T elem)
    {
        if(h)
        {
            if(h->left) find_help(h->left,u,elem);
            if (!(h->value!=elem))
            {
                u.node=h;
            }
            if(h->right) find_help(h->right,u,elem);
        }
    }
};

class persona
{
private:
    int id;
    static int idgen;
    string fam;
    string name;
    string och;
    string whybad;
public:
    persona();
    persona(int m_id, string m_fam,string m_name,string m_och,string m_whybad);
    persona(const persona &pers);
    ~persona(){}
    friend istream& operator>>(istream& in, persona&pers);
    friend ostream& operator<<(ostream& out,const persona&pers);
    friend bool operator>(const persona&chel1, const persona&chel2);
    friend bool operator<(const persona&chel1, const persona&chel2);
    friend bool operator==(const persona&chel1, const persona&chel2);
    friend bool operator!=(const persona&chel1, const persona&chel2);
    int get_id(){return id;}
    string get_fam(){return fam;}
    string get_name(){return name;}
    string get_och(){return och;}
};

void del(bin_tree<persona>&);
int checker();
void imghead();
void showhead();
void showend();
void showmenu();
void showhead1();
void showend1();
#include <iostream>

using namespace std;

template <typename T>
class HList
{
private:
    struct elem
    {
        T data;
        elem *next;
    };
    elem *head;
public:
    HList() {head=NULL;}

    void HList_add_head (T d)
    {elem *el;
        el=new elem;
        el->data=d;
        el->next=head;
        head=el;
    }

    void HList_add_last (T d)
    {elem *el,*q=head;
        while(q->next)
        {q=q->next;}
        el=new elem;
        el->data=d;
        el->next=NULL;
        q->next=el;
    }

    void HList_delete_last()
    {elem *q=head;
        while(q->next->next)
        {q=q->next;}
    elem *destr=q->next;
        q->next=NULL;
        delete destr;
    }

    void HList_display()
    {elem *curr=head;
        while(curr)
        {
            cout<<curr->data<<endl;
            curr=curr->next;
        }
    }

    ~HList()
    {elem *curr=head;
        while(curr)
        {elem* destr=curr;
            curr=curr->next;
            delete destr;
        }
        cout<<"Delete is good\n";
    }
    class Iterator
    {
    private:
        elem *curr;
    public:
        Iterator()
        {
            curr=NULL;
        }

        Iterator(elem *c)
        {
            //curr = new elem;
            curr=c;
        }

        ~Iterator()
        {
            //delete current;
            cout<<"delete iterator";
        }

        Iterator& operator++ ()
        {
            curr=curr->next;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator saved=*this;
            curr=curr->next;
            return saved;
        }

        bool operator!=(const Iterator &second)
        {
            return curr!=second.curr;
        }

        T operator*()
        {
            return curr->data;
        }

        T *operator->()
        {
            return *(curr->data);
        }

    };

    Iterator begin() const {Iterator current=head;return current;}

    Iterator end() const {/*Iterator current=NULL;*/return NULL;}

    class Failed{};
    HList (const HList& orig)
    {
        throw Failed();
    }
    HList& operator=(const HList& orig)
    {
        throw Failed();
    }
};
int main()
{
    HList<int> Hell;

    Hell.HList_add_head(24);
    Hell.HList_display();
    cout<<"****"<<endl;

    Hell.HList_add_last(10);
    Hell.HList_add_head(40);
    Hell.HList_display();
    cout<<"****"<<endl;

    Hell.HList_delete_last();
    Hell.HList_display();
    cout<<"****"<<endl;

    try {HList<int> Hell2=Hell; }

    catch (HList<int>::Failed)
    {
        cout<<"Don't Use!\n";
    }
    try {HList<int> Hell2; Hell2=Hell; }
    catch (HList<int>::Failed)
    {
        cout<<"Don't Use!\n";
    }
    Hell.HList_add_last(33);
    Hell.HList_display();
    cout<<"****"<<endl;

    /*Hell.HList_delete_last();
    Hell.HList_display();
    cout<<"****"<<endl;*/
    /*HList<int>::Iterator i=Hell.begin();
    cout<<*i;
    ++i;
    cout<<*i;*/
    for(HList<int>::Iterator i=Hell.begin(); i!=Hell.end(); ++i)
    {
        cout<<*i<<endl;
    }
    return 0;
}

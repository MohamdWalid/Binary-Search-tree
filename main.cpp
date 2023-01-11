#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<bits/stdc++.h>;
using namespace std;
int count1=0;
class node
{
public:
    string data;
    int priority;
    node *left;
    node *right;

};
class BST
{
private:
    vector<string> arr2;
    vector<int> arr1;
public:
    node *root=NULL;
    int max1=0;
    string word2;
    void read_file()
    {
        ifstream my_file;
        vector<string> file1;
        my_file.open("task2.txt");
        string word;
        if(my_file.is_open())
        {
            while(getline(my_file,word))
            {
                stringstream ss;
                ss << word;
                string temp;
                int found1;
                string found2;
                while (!ss.eof())
                {
                    ss >> temp;
                    if(stringstream(temp) >> found1)
                    {
                        arr1.push_back(found1);
                    }
                    if(stringstream(temp) >> found2)
                    {
                        file1.push_back(found2);

                    }
                }

            }
            my_file.close();
        }
        else
        {
            cout<<" file isn't open "<<endl;
        }
        for(int i=0; i<file1.size(); i=i+2)
        {
            arr2.push_back(file1[i]);
        }
        for(int i=0; i<arr2.size();i++)
        {
            insert1(arr1[i],arr2[i]);
        }
    }
    void insert4()
    {
        count1=0;
       for(int i=arr1.size()-1;i>=0;i--)
        {
            arr1.pop_back();
            arr2.pop_back();
        }
        inorderinsert(root);
        root=NULL;
        for(int i=0; i<arr2.size();i++)
        {
            insert1(arr1[i],arr2[i]);
        }
    }
    void insert3()
    {
        count1=0;
        for(int i=arr1.size()-1;i>=0;i--)
        {
            arr1.pop_back();
            arr2.pop_back();
        }
        inorderinsert(root);
        root=NULL;
        for(int i=0; i<arr2.size();i++)
        {
            insert2(arr1[i],arr2[i]);
        }
    }
    void inorderinsert(node* current)
    {
        if(current != NULL)
        {
            inorderinsert(current->left);
            arr1.push_back(current->priority);
            arr2.push_back(current->data);
            inorderinsert(current->right);
        }
    }
    void insert2(int prior,string item)
    {
       node *node1=new node;
       node1->data=item;
       node1->priority=prior;
       node1->left=NULL;
       node1->right=NULL;
       node *current= root;
       node *behind;
       if(root == NULL)
       {
           root = node1;
       }
       else if(count1==1)
       {
           if(prior > current->priority)
                current->right =node1;
            else
                current->left=node1;
       }
       else
       {
            while(current!=NULL)
            {
                behind=current;
                if(prior > current->priority)
                    current = current->right;
                else
                    current = current->left;
            }
            if(prior > behind->priority)
                behind->right =node1;
            else
                behind->left=node1;

       }
       count1++;
    }
    void insert1(int prior,string item)
    {
       node *node1=new node;
       node1->data=item;
       node1->priority=prior;
       node1->left=NULL;
       node1->right=NULL;
       node *current= root;
       node *behind;
       if(root == NULL)
       {
           root = node1;
       }
       else if(count1==1)
       {
           if(item > current->data)
                current->right =node1;
            else
                current->left=node1;
       }
       else
       {
            while(current!=NULL)
            {
                behind=current;
                if(item > current->data)
                    current = current->right;
                else
                    current = current->left;
            }
            if(item > behind->data)
                behind->right =node1;
            else
                behind->left=node1;

       }
       count1++;
    }
    bool search_by_name(string item)
    {
        node *current = root;
        while(current != NULL)
        {
            if(current->data == item)
                return true;
            else if(current->data < item)
                current = current->right;
            else
                current = current->left;
        }
        return false;
    }
    void inordersearch(node* current)
    {
        if(current != NULL)
        {
            inordersearch(current->left);
            if(max1 < current->priority)
            {
                max1=current->priority;
                word2=current->data;
            }
            inordersearch(current->right);
        }
    }
    void inorderprint(node* current)
    {
        if(current != NULL)
        {
            inorderprint(current->left);
            cout<<current->data<<" "<<current->priority<<endl;
            inorderprint(current->right);
        }
    }
    void searchTopPriority(string check)
    {
        if(count1==0)
        {
            cout<<"cannot delete this is empty tree."<<endl;
        }
        else
        {
            inordersearch(root);
            cout<<max1<<" "<<word2<<endl;
            if(check=="name")
            {
                removeTopPriority1(word2);
            }
            else
            {
               removeTopPriority2(max1);
            }

            count1--;
            max1=0;
        }

    }
    void removeTopPriority1(string item)
    {
        node *current=root;
        node *behind=root;
        if(root->data == item)
        {
            delete1(root);
        }
        if(root->data > item)
            current = root->left;
        else
            current = root->right;
        while(current != NULL)
        {
            if(current->data == item)
                break;
            else
            {
                behind = current;
                if(current->data > item)
                    current = current->left;
                else
                    current = current->right;
            }
        }
        if(behind->data > item)
            delete1(behind->left);
        else
            delete1(behind->right);
    }
    void removeTopPriority2(int item)
    {
        if(count1==0)
        {
            cout<<"cannot delete this is empty tree."<<endl;
        }
        else
        {
            node *current=root;
            node *behind=root;
            if(root->priority == item)
            {
                delete1(root);
            }
            if(root->priority > item)
                current = root->left;
            else
                current = root->right;
            while(current != NULL)
            {
                if(current->priority == item)
                    break;
                else
                {
                    behind = current;
                    if(current->priority > item)
                        current = current->left;
                    else
                        current = current->right;
                }
            }
            if(behind->priority > item)
                delete1(behind->left);
            else
                delete1(behind->right);
        }
    }
    void delete1(node* &p)
    {
      node *current;
     node *behind;
     node *temp;

	 if(p->left == NULL && p->right == NULL)
     {
		delete p;
		p = NULL;
     }
     else if(p->left == NULL)
     {
		temp = p;
        p = p->right;
        delete temp;
     }
     else if(p->right == NULL)
     {
		temp = p;
        p = p->left;
        delete temp;
     }
     else
     {
        current = p->left;
        behind = NULL;

        while(current->right != NULL)
        {
            behind = current;
            current = current->right;
        }

        p->data = current->data;

        if(behind == NULL)

           p->left = current->left;
        else
           behind->right = current->left;
        delete current;
     }
    }
    void print()
    {
        inorderprint(root);
    }

};
int main()
{
    BST o;
    o.read_file();
    int priority;
    string item;
    int choice1,choice2;
    string check="name";
    while(true)
    {
        do
        {
            cout<<"[1] insert"<<endl;
            cout<<"[2] remove TopPriority"<<endl;
            cout<<"[3] search by Name "<<endl;
            cout<<"[4] print"<<endl;
            cout<<"[5] BST sorted by priority"<<endl;
            cout<<"[6] BST sorted by name"<<endl;
            cout<<"choice: "<<endl;
            cin>>choice1;
        }
        while(choice1<=0 || choice1 > 6);
        switch(choice1)
        {
        case 1:
            cout<<"Enter priority: ";
            cin>>priority;
            cout<<"Enter item: ";
            cin>>item;
            if(check=="name")
            {
                o.insert1(priority,item);
            }
            else
            {
                o.insert2(priority,item);
            }
            break;

        case 2:
            o.searchTopPriority(check);
            break;

        case 3:
            cout<<"Enter item: ";
            cin>>item;
            if(o.search_by_name(item))
            {
                cout<<"found item"<<endl;
            }
            else
            {
                cout<<"not found item"<<endl;
            }
            break;

        case 4:
            o.print();
            break;

        case 5:
            if(check=="name")
            {
                o.insert3();
            }
            check="priority";
            break;
        case 6:
            if(check=="priority")
            {
                o.insert4();
            }
            check="name";
            break;
        }
        cout<<"Do you want continue(1/0)"<<endl;
        cin>>choice2;
        if(choice2!=1)
        {
            break;
        }
    }
    return 0;
}

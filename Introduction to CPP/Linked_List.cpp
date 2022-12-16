template<typename T>
class Lisst_Node{
    public: 
    List_Node(const T& data);
    List_Node<T>* next();
private:
List_Node<T>* next_m;
List_Node<T>* prev_m;
T data_m;

friend class List<T>;
}


void List {
    public:
    List();
    void append(const T& item);
    private:
    List_Node<T>* head_m;
    List_Node<T>* tail_m;
}

tmplate<typename T>
List<T>::List(): head_m(0),tail_m(0){}


template<typename T>
void List<T>:: append(const T& item){
    List_Node<T>* new_node = new List_Node<T>(item);
    if (! tail_m){
        head_m = tail_m = new_node;
    }else{
tail_m -> next_m = new_node;
new_node-> prev_m = tail_m;
tail_m = new_node;
    }
}
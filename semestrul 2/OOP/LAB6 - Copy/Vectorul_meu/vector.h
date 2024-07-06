
template<typename TElem>
class IteratorNou;

template<typename TElem>
class VectorulMeu{
private:
    int cp;
    int n;
    TElem* elems;
    void redim();
public:
    VectorulMeu();
    VectorulMeu(const VectorulMeu& ot);
    VectorulMeu<TElem>& operator=(const VectorulMeu<TElem>& ot);
    TElem& operator[](int poz) const;
    void push_back(const TElem& p);
    void pop_back();
    int size() const;
    bool empty() const;
    int get_cp() const;
    ~VectorulMeu();
    friend class IteratorNou<TElem>;
    IteratorNou<TElem> begin();
    IteratorNou<TElem> end();
};

template<typename TElem>
VectorulMeu<TElem>::VectorulMeu() : cp{2}, n{0}, elems{new TElem[cp]} {}

template<typename TElem>
VectorulMeu<TElem>::VectorulMeu(const VectorulMeu& ot)
{
    auto* new_elems = new TElem[ot.cp];
    cp = ot.cp;
    n=ot.n;
    for(int i=0; i<ot.cp; i++)
        new_elems[i] = ot.elems[i];
    elems = new_elems;
}

template<typename TElem>
VectorulMeu<TElem>& VectorulMeu<TElem>::operator=(const VectorulMeu<TElem> &ot) {
    delete[] elems;
    auto* new_elems = new TElem[ot.cp];
    cp = ot.cp;
    n=ot.n;
    for(int i=0; i<ot.cp; i++)
        new_elems[i] = ot.elems[i];
    elems = new_elems;
    return *this;
}

template<typename TElem>
TElem& VectorulMeu<TElem>::operator[](int poz) const {
    return elems[poz];
}

template<typename TElem>
void VectorulMeu<TElem>::VectorulMeu::push_back(const TElem &p) {
    if(n==cp)
        redim();
    elems[n++]=p;
}

template<typename TElem>
void VectorulMeu<TElem>::pop_back(){
    n--;
}

template<typename TElem>
int VectorulMeu<TElem>::VectorulMeu::size() const{
    return n;
}


template<typename TElem>
void VectorulMeu<TElem>::VectorulMeu::redim() {
    auto* new_elems=new TElem[cp*2];
    cp*=2;
    for(int i=0;i<n;i++)
        new_elems[i]=elems[i];
    delete[] elems;
    elems=new_elems;
}

template<typename TElem>
int VectorulMeu<TElem>::VectorulMeu::get_cp() const{
    return cp;
}

template<typename TElem>
bool VectorulMeu<TElem>:: empty() const{
    return n==0;
}

template<typename TElem>
VectorulMeu<TElem>::~VectorulMeu(){
    delete[] elems;
}

template<typename TElem>
class IteratorNou {
private:
    const VectorulMeu<TElem>& v;
    int poz = 0;
public:
    IteratorNou(const VectorulMeu<TElem>& v) noexcept;
    IteratorNou(const VectorulMeu<TElem>& v, int poz)noexcept;
    bool valid()const noexcept;
    TElem& element() const noexcept;
    void next() noexcept;
    TElem& operator*();
    IteratorNou& operator++();
    bool operator==(const IteratorNou& ot)noexcept;
    bool operator!=(const IteratorNou& ot)noexcept;
};

template<typename TElem>
IteratorNou<TElem> VectorulMeu<TElem>::begin()
{
    return IteratorNou<TElem>(*this);
}

template<typename TElem>
IteratorNou<TElem> VectorulMeu<TElem>::end()
{
    return IteratorNou<TElem>(*this, n);
}

template<typename TElem>
IteratorNou<TElem>::IteratorNou(const VectorulMeu<TElem> &v) noexcept:v{ v }{}

template<typename TElem>
IteratorNou<TElem>::IteratorNou(const VectorulMeu<TElem> &v, int poz) noexcept :v{ v }, poz{ poz } {}

template<typename TElem>
bool IteratorNou<TElem>::valid()const noexcept {
    return poz < v.lg;
}

template<typename TElem>
TElem& IteratorNou<TElem>::element() const noexcept {
    return v.elems[poz];
}

template<typename TElem>
void IteratorNou<TElem>::next() noexcept {
    poz++;
}

template<typename TElem>
TElem& IteratorNou<TElem>::operator*() {
    return element();
}

template<typename TElem>
IteratorNou<TElem>& IteratorNou<TElem>::operator++() {
    next();
    return *this;
}

template<typename TElem>
bool IteratorNou<TElem>::operator==(const IteratorNou<TElem>& ot) noexcept {
    return poz == ot.poz;
}

template<typename TElem>
bool IteratorNou<TElem>::operator!=(const IteratorNou<TElem>& ot)noexcept {
    return !(*this == ot);
}



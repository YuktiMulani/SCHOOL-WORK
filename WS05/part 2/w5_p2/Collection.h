#ifndef _COLLECTION_H
#define _COLLECTION_H

namespace sdds {
    template<typename T>
    class Collection {
    private:
        std::string m_name = "";
        T* m_arr = nullptr;
        size_t m_size = 0;
        void (*observer) (const Collection<T>& C, const T& data) = nullptr;
    public:
        Collection(const std::string& name)
        {
            this->m_name = name;
        }

        Collection(const Collection<T>& C) = delete;

        ~Collection()
        {
            delete[] this->m_arr;
        }

        const std::string& name() const
        {
            return this->m_name;
        }

        size_t size() const
        {
            return this->m_size;
        }

        void setObserver(void (*observer)(const Collection<T>& C, const T& data))
        {
            this->observer = observer;
        }

        Collection<T>& operator+=(const T& item)
        {
            for (size_t i = 0; i < this->m_size; ++i)
                if (this->m_arr[i].title() == item.title())
                    return *this;
            T* tmp = new T[this->m_size + 1];
            for (size_t i = 0; i < this->m_size; ++i)
                tmp[i] = this->m_arr[i];
            tmp[this->m_size++] = item;
            delete[] this->m_arr;
            this->m_arr = tmp;
            if (this->observer != nullptr)
                this->observer(*this, item);

            return *this;
        }

        T& operator[](size_t idx) const
        {
            if (idx >= this->m_size) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->m_size) + "] items.");
            }
            return this->m_arr[idx];
        }

        T* operator[](const std::string& title) const
        {
            for (size_t i = 0; i < this->m_size; ++i) {
                if (this->m_arr[i].title() == title)
                    return &(this->m_arr[i]);
            }
            return nullptr;
        }

        friend std::ostream& operator<<(std::ostream& ostr, Collection<T>& C)
        {
            for (size_t i = 0; i < C.m_size; ++i) {
                ostr << (C.m_arr[i]);
            }
            return ostr;
        }
    };

}

#endif

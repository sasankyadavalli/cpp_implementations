// #include <iostream>
// #include <new>
// #include <utility>
// #include <vector.hpp>

// template <typename T>
// class Vector
// {
// private:
// 	std::size_t size_;
// 	std::size_t capacity_;
// 	T *data_;


// 	/*
// 		This is currently not exception safe. Should revisit. 
// 	*/
// 	void grow()
// 	{
// 		std::size_t new_capacity_ = (capacity_ == 0) ? 1 : 2 * capacity_;
// 		T *temp = static_cast<T*>(::operator new(new_capacity_ * sizeof(T)));
// 		for (std::size_t i = 0; i < size_; i++)
// 		{
// 			new (temp + i) T(std::move(data_[i]));
// 			data_[i].~T();
// 		}
// 		::operator delete(data_);
// 		data_ = temp;
// 		capacity_ = new_capacity_;
// 	}

// public:
// 	Vector(const Vector &other)
// 		: capacity_(other.capacity_), size_(other.size_)
// 	{

// 		data_ = static_cast<T*>(::operator new(other.capacity_ * sizeof(T)));
// 		for (std::size_t i = 0; i < other.size_; i++)
// 		{
// 			try {
// 				new (data_ + i) T(other.data_[i]);
// 			}
// 			catch(...) {
// 				for(std::size_t j = 0; j < i; j++) {
// 					data_[j].~T();
// 				}

// 				::operator delete(data_);
// 				throw;
// 			}
// 		}
// 	}

// 	// Move constructor
// 	Vector(Vector &&other) noexcept
// 		: capacity_(other.capacity_), size_(other.size_), data_(other.data_)
// 	{

// 		other.data_ = nullptr;
// 		other.capacity_ = 0;
// 		other.size_ = 0;

// 		std::cout << "Move constructor ended" << std::endl;
// 	}

// 	// Default constructor
// 	Vector(size_t capacity)
// 		: capacity_(capacity)
// 	{
// 		data_ = static_cast<T *>(::operator new(capacity * sizeof(T)));
// 		size_ = 0;
// 	}

// 	~Vector()
// 	{
// 		for (std::size_t i = 0; i < size_; i++)
// 		{
// 			data_[i].~T();
// 		}
// 		::operator delete(data_);
// 	}

// 	void push_back(const T &obj)
// 	{
// 		if (size_ == capacity_)
// 		{
// 			grow();
// 		}
// 		new (data_ + size_) T(obj);
// 		++size_;
// 	}
	
// 	template <typename... Args>
// 	void emplace_back(Args &&...args)
// 	{ 
// 		if (size_ == capacity_)
// 		{
// 			grow();
// 		}
// 		new (data_ + size_) T(std::forward<Args>(args)...);
// 		++size_;
// 	}

// 	std::size_t size() const noexcept
// 	{
// 		return size_;
// 	}

// 	void swap(Vector& other) noexcept {
// 		using std::swap;

// 		swap(data_, other.data_);
// 		swap(capacity_, other.capacity_);
// 		swap(size_, other.size_);
// 	}

// 	friend void swap(Vector& a, Vector& b) noexcept {
// 		a.swap(b);
// 	}

// 	T &operator[](std::size_t index)
// 	{
// 		return data_[index];
// 	}

// 	Vector &operator=(const Vector& other)
// 	{
// 		if (&other == this)
// 		{
// 			return *this;
// 		}

// 		if (this->capacity_ >= other.capacity_)
// 		{
// 			for (std::size_t i = 0; i < std::min(this->size_, other.size_); i++)
// 			{
// 				this->data_[i] = other.data_[i];
// 			}

// 			if (this->size_ >= other.size_)
// 			{
// 				for (std::size_t i = other.size_; i < this->size_; i++)
// 				{
// 					this->data_[i].~T();
// 				}

// 				this->size_ = other.size_;
// 			}
// 			else
// 			{
// 				for (std::size_t i = this->size_; i < other.size_; i++)
// 				{
// 					new (data_ + i) T(other.data_[i]);
// 					this->size_ += 1;
// 				}
// 			}
// 			return *this;
// 		}

// 		T *temp = static_cast<T*>(::operator new(other.capacity_ * sizeof(T)));

// 		for (std::size_t i = 0; i < other.size_; i++)
// 		{
// 			try
// 			{
// 				new (temp + i) T(other.data_[i]);
// 			}
// 			catch (...)
// 			{
// 				for (std::size_t j = 0; j < i; ++j)
// 				{
// 					temp[j].~T();
// 				}
// 				::operator delete(temp);

// 				throw;
// 			}
// 		}

// 		std::swap(this->data_, temp);

// 		for (std::size_t i = 0; i < size_; i++)
// 		{
// 			temp[i].~T();
// 		}

// 		capacity_ = other.capacity_;
// 		size_ = other.size_;

// 		::operator delete(temp);

// 		return *this; //
// 	}

// 	Vector &operator=(Vector&& other) noexcept
// 	{
// 		if (this == &other)
// 		{
// 			return *this;
// 		}

// 		for (std::size_t i = 0; i < this->size_; i++)
// 		{
// 			data_[i].~T();
// 		}

// 		::operator delete(this->data_);

// 		this->data_ = other.data_;
// 		this->capacity_ = other.capacity_;
// 		this->size_ = other.size_;

// 		other.data_ = nullptr;
// 		other.capacity_ = 0;
// 		other.size_ = 0;

// 		return *this;
// 	}
// };

// int main()
// {
// 	// Vector<int> v(2);
// 	// Vector<int> c(10);
// 	// v.push_back(11);
// 	// c = v;

// 	// Vector<int> a(5);
// 	// Vector<int> b(5);
// 	// a.push_back(1);
// 	// a.push_back(2);
// 	// a.push_back(3);
// 	// b.push_back(4);
// 	// b.push_back(5);

// 	// using std::swap;
// 	// swap(a, b);

// 	// for (size_t i = 0; i < b.size(); i++)
// 	// {
// 	// 	std::cout << b[i] << "\n";
// 	// }

// 	// for(size_t i = 0; i < a.size(); i++) {
// 	// 	std::cout << a[i] << "\n";
// 	// }
// 	// return 0;
// }

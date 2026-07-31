#include <iostream>
#include <new>

template <typename T> class Vector {
	private:
		std::size_t size_;
		std::size_t capacity_;
		T* data_;

	public:
		Vector(size_t capacity)
			: capacity_(capacity){
			      	data_ = static_cast<T*>(std::malloc(capacity * sizeof(T)));
				size_ = 0;	
			}

		~Vector(){
			for(int i=0;i<size_;i++){
				data_[i].~T();
			}
			std::free(data_);
			size_ = 0;
			capacity_ = 0;
		}

		void push_back(const T& obj){
			if(size_ == capacity_){
				std::size_t new_capacity_ = (capacity_ == 0) ? 1 : 2*capacity_;
				T* temp = static_cast<T*>(std::malloc(new_capacity_ * sizeof(T)));
				for(int i = 0; i < size_;i++){
					new (temp + i) T(std::move(data_[i]));
					data_[i].~T();
				}
				std::free(data_);
				data_ = temp;
				capacity_ = new_capacity_;
			}
			new (data_ + size_) T(obj); 
			size_ += 1;
		}

		int size() {
			return size_;
		}

		T& operator[](std::size_t index){
			return data_[index];
		}
};

int main() {
	Vector<std::string> v(2);
	v.push_back("Hello");
	v.push_back("World");
	v.push_back("C++");
	
	for(size_t i = 0; i < v.size();i++){
		std::cout << v[i] << "\n"; 
	}
	return 0;
}

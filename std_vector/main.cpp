#include <iostream>
#include <new>
#include <utility>

template <typename T> class Vector {
	private:
		std::size_t size_;
		std::size_t capacity_;
		T* data_;

		void grow() {
                         std::size_t new_capacity_ = (capacity_ == 0) ? 1 : 2*capacity_;
                         T* temp = static_cast<T*>(std::malloc(new_capacity_ * sizeof(T)));
                         for(std:size_t i = 0; i < size_;i++){
                                 new (temp + i) T(std::move(data_[i]));
                                 data_[i].~T();
                         }
                         std::free(data_);
                         data_ = temp;
                         capacity_ = new_capacity_;
                }


	public:
		// COPY CONSTRUCTOR
		// MOVE CONSTRUCTOR
		// 

			Vector(Vector&& other) {
		    other.data_ = this.data_;
		    other.capacity_ = this.capacity_;
		    other.size_ = this.size_;
		    
		    this.data_ nullptr;
		    this.capacity_ = 0;
		    this.size_ = 0;
		}
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
		}

		void push_back(const T& obj) {
			if(size_ == capacity_){
				grow();
			}
			new (data_ + size_) T(obj); 
			++size_;
		}	
		// template parameter pack
		template<typename... Args> 
		void emplace_back(Args&&... args){ //function parameter pack()
			if(size_ == capacity_) {
				grow();
			}
			new (data_ + size_) T(std::forward<Args>(args)...);
			++size_;
		
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
	v.emplace_back("emplace");
	
	for(size_t i = 0; i < v.size();i++){
		std::cout << v[i] << "\n"; 
	}
	return 0;
}

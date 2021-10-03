#pragma once
#include <assert.h>
#include <vector> // Req. by vectors
#include <memory> // Req. by Smart pointers
/*
	Template for for creating new Object Containers
	Full Implementation in header file
*/

using namespace std;

namespace myNameSpace
{
	/*
		Template Input
			T : The object you want to store in the container, def. to int
	*/
	template <class T = int>
	/*
		Class used to store one object of any type
	*/
	class myContainer
	{
	private:
		T	item_;

	public:
		/*
			Def. Constructor
		*/
		myContainer(T otherItem_)
		{
			// Update thisItem
			this->item_ = otherItem_;

		}

		/*
			Copy Constructor
		*/
		myContainer(const myContainer& otherContainer_)
		{
			this->item_ = otherContainer_.item_;
		}

		/*
			Destructor
		*/
		~myContainer()
		{

		}

		// Get/Set functions
		/*
			Function used to get the object contained it thisContainer
		*/
		T	get()
		{
			return this->item_;
		}


		/*
			Function used to set the object contained in thisContainer
		*/
		void set(const myContainer otherContainer_)
		{
			this->item_ = otherContainer_.item_;
		}
		/*
			Function used to set the object contained in thisContainer
		*/
		void	set(const T otherItem_)
		{
			this->item_ = otherItem_;
		}
		
	};

	/*
		Template Input
			T : The object you want to store in the container, default to int
	*/
	template <class T = int>
	/*
		Class used to store and array of n object of any type
	*/
	class myDynamicContainer
	{
	private:
		unique_ptr<T[]>	items_;
		int size_;

	public:
		/*
			Def. Constructor
		*/
		myDynamicContainer()
		{
			// Init smart pointer
			this->items_ =  make_unique<T[]>();
		}

		myDynamicContainer(T otherItem_)
		{		
			// Init Item Array
			this->items_ = make_unique<T[]>(1);

			// Update firstItem and array size
			this->items_[0] = otherItem_;
			this->size_ = 1;
		}

		/*
			Copy Constructor
		*/
		myDynamicContainer(const myDynamicContainer& otherContainer_)
		{
			// Does otherContainer have any items?
			if (otherContainer_.size_ == 0)
			{
				// N-> Forced exit nothing to copy
				return;
			}

			// Keep track of prevSize
			int prevSize = this->size_;

			// Resize this container so it can contain otherContainers items
			this->resize(this->size_ + otherContainer_.size_);
						
			// Copy each item of otherContainer to thisContainer
			for (int ix = 0; ix < this->size_; ix++)
			{
				this->items_[ix] = otherContainer_.items_[ix];
			}
		}

		/*
			Destructor
		*/
		~myDynamicContainer()
		{
			// No need to destroy the item array since we use a smart pointer
		}

		// Get/Set functions
		/*
			Function used to get the object contained it thisContainer
		*/
		T	get(int ix_ = 0)
		{
			// Is specified ix valid?
			assert(ix_ >= 0 && ix_ < this->size_);
			
			// Assume Y->Return the item
			return this->items_[ix_];
		}


		/*
			Function used to set object at specified ix in thisContainer item Array
		*/
		void	set(const T otherItem_, int ix_ = 0)
		{
			// Is specified ix valid?
			assert(ix_ >= 0 && ix_ < this->size_);

			// Set item at specified ix to otherItem
			//**this->items_[ix_] = otherItem_;
			this->items_[ix_] = otherItem_;
		}

		/*
			Function used to resize item array of thisContainer
		*/
		int resize(int newSize_ = 1)
		{
			// Create new array of specified size
			unique_ptr<T> pItemArray = new T[newSize_];

			// Does thisContainer contain any items?
			if (this->size_ > 0)
			{
				//Y-> Copy thisConatiner items to new array
				for (int ix = 0; ix < this.size_; ix++)
				{
					pItemArray[ix] = this->items_[ix];
				}
			}


			// Resize thisConatiner item array
			this->items_ = pItemArray;

			// Update thisContainer size
			this->size_ = newSize_;

			// Return new size of thisConatiner
			return this->size_;
		}

		/*
			Function used to add a new item_ 
		*/

		// Operator overloads

	};

	/*
		Template Input
			T : The object you want to store in the container, default to int
	*/
	template <class T = int>
	/*
		Class used to store and array of n object of any type using STL vector
	*/
	class vectorContainer
	{
	private:
		std::vector<T> items_;

	public:
		/*
			Def. Constructor
		*/
		vectorContainer()
		{
			//**this.items_ = nullptr;
		}

		vectorContainer(T otherItem_)
		{
			// Init Item Vector
			this->items_.resize(1);

			// Update firstItem
			this.items_[0] = otherItem_;
		}

		/*
			Copy Constructor
		*/
		vectorContainer(const vectorContainer& otherContainer_)
		{
			// Does otherContainer have any items?
			if (otherContainer_.items_.empty())
			{
				// N-> Forced exit nothing to copy
				return;
			}

			// Keep track of prevSize
			int prevSize = this->items_.size;

			// Resize this container so it can contain otherContainers items
			this.items_.resize(this.size_ + otherContainer_.size_);

			// Copy each item of otherContainer to thisContainer
			for (int ix = 0; ix < this.size_; ix++)
			{
				this.items_[ix] = otherContainer_.items_[ix];
			}
		}

		/*
			Destructor
		*/
		~vectorContainer()
		{
			// Does thisContainer have any items?
			if (this.size_ > 0)
			{
				//Y-> Dealloc thisContainers item array
				delete[] items_;
			}
		}

		// Get/Set functions
		/*
			Function used to get the object contained it thisContainer
		*/
		T	get(int ix_ = 0)
		{
			// Is specified ix valid?
			assert(ix_ >= 0 && ix_ < this->size_);

			// Assume Y->Return the item
			return this.items_[ix_];
		}


		/*
			Function used to set object at specified ix in thisContainer item Array
		*/
		void	set(const T otherItem_, int ix_ = 0)
		{
			// Is specified ix valid?
			assert(ix_ >= 0 && ix_ < this->size_);

			// Set item at specified ix to otherItem
			this.items_[ix_] = otherItem_;
		}

		/*
			Function used to resize item array of thisContainer
		*/
		int resize(int newSize_ = 1)
		{
			// Create new array of specified size
			T newItemArray[newSize_];

			// Does thisContainer contain any items?
			if (this.size_ > 0)
			{
				//Y-> Copy thisConatiner items to new array
				for (int ix = 0; ix < this.size_; ix++)
				{
					newItemArray[ix] = this.items_[ix];
				}
			}


			// Resize thisConatiner item array
			this.items_ = newItemArray;

			// Update thisContainer size
			this.size_ = newSize_;

			// Return new size of thisConatiner
			return this.size_;
		}

		/*
			Function used to add a new item_
		*/

		// Operator overloads

	};
}


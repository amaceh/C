/*
	Class BookStore
	- BookStoreCode
	- BookStoreName
	- BookStoreAddress
	- SellerCode
	Inheritance dari class Book seller
*/

class BookStore extends BookSeller{
	//attribute yang tidak ada pada kelas bapak
	private String BookStoreCode;
	//blank contructor
	BookStore(){

	}
	//set method
	public void setStoreCode(String code){
		this.BookStoreCode = code;
	}

	//get method
	public String getStoreCode(){
		return this.BookStoreCode;
	}
}
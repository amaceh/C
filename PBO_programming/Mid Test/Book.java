class Book{
	private String BookCode, BookTitle, BookGenreCode, BookStoreCode, PublisherCode;

	Book(){

	}

	public void setCode(String code){
		this.BookCode = code;
	}
	public String getCode(){
		return this.BookCode;
	}

	public void setTitle(String title){
		this.BookTitle = title;
	}
	public String getTitle(){
		return this.BookTitle;
	}

	public void setGenreCode(String code){
		this.BookGenreCode = code;
	}
	public String getGenreCode(){
		return this.BookGenreCode;
	}

	public void setStoreCode(String code){
		this.BookStoreCode = code;
	}
	public String getStoreCode(){
		return this.BookStoreCode;
	}

	public void setPublisherCode(String code){
		this.PublisherCode = code;
	}
	public String getPublisherCode(){
		return this.PublisherCode;
	}
}
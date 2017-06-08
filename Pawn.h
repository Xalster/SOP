class Pawn
{
	public:
	Pawn();
	~Pawn();

		int getCol();
		int getRow();
		void goRight(int y);
		void goLeft(int y);
		void goUp(int x);
		void goDown(int x);
		void placePawn(int x, int y);
		void updatePawnPos(int row, int col);
		void updateMatrix(int row, int col);
	
	private:
		int col;
		int row;
}

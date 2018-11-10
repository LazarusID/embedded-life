package life

type Board struct {
	cell         [2][64][64]bool
	currentBoard int
	futureBoard  int
}

// NewBoard Board Constructor
func NewBoard() *Board {
	b := new(Board)
	b.currentBoard = 0
	b.futureBoard = 1

	return b
}

// SetFutureState defines the desired state of the board
func (b *Board) SetFutureState(x int, y int, alive bool) {
	b.cell[b.futureBoard][x][y] = alive
}

// GetCurrentState returns the current state of a single cell on the board
func (b *Board) GetCurrentState(x int, y int) bool {
	return b.cell[b.currentBoard][x][y]
}

// Tick makes the future state of the board into the current state
func (b *Board) Tick() {
	if b.currentBoard == 0 {
		b.currentBoard = 1
		b.futureBoard = 0
	} else {
		b.currentBoard = 0
		b.futureBoard = 1
	}
}

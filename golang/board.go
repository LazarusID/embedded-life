package life

type Board struct {
	cell         [2][64][64]bool
	currentBoard int
	futureBoard  int

	XMax int
	YMax int
}

// NewBoard Board Constructor
func NewBoard() *Board {
	b := new(Board)
	b.currentBoard = 0
	b.futureBoard = 1
	b.XMax = 64
	b.YMax = 64

	return b
}

// SetFutureState defines the desired state of the board
func (b *Board) SetFutureState(x int, y int, alive bool) {
	if x >= 0 && y >= 0 && x < b.XMax && y < b.YMax {
		b.cell[b.futureBoard][x][y] = alive
	}
}

// GetCurrentState returns the current state of a single cell on the board
func (b *Board) GetCurrentState(x int, y int) bool {
	if x >= 0 && y >= 0 && x < b.XMax && y < b.YMax {
		return b.cell[b.currentBoard][x][y]
	}
	return false

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
	b.clearFutureCells()
}

func (b *Board) clearFutureCells() {
	for i := 0; i < b.XMax; i++ {
		for j := 0; j < b.YMax; j++ {
			b.SetFutureState(i, j, false)
		}
	}
}

// Neighbors returns the number of alive cells adjacent cells on the current board.
// The current cell is not counted as one of the neighbors.
func (b *Board) Neighbors(x int, y int) int {
	count := 0
	for i := -1; i < 2; i++ {
		for j := -1; j < 2; j++ {
			if x != i || y != j {
				if b.GetCurrentState(x+i, y+j) {
					count++
				}
			}
		}
	}
	return count
}

package life

import (
	"testing"
)

func Test_GetCurrentState_afterSetFutureStateAndTick_returnsTrue(t *testing.T) {
	b := NewBoard()
	b.SetFutureState(1, 1, true)
	b.Tick()
	actual := b.GetCurrentState(1, 1)
	if actual != true {
		t.Errorf("Expected true, got %t", actual)
	}
}

func Test_GetCurrentState_afterTick_returnsFalse(t *testing.T) {
	b := NewBoard()
	b.Tick()
	actual := b.GetCurrentState(2, 2)
	if actual != false {
		t.Errorf("Expected false, got %t", actual)
	}
}

func Test_GetCurrentState_AfterSetFutureBeforeTick_returnsFalse(t *testing.T) {
	b := NewBoard()
	b.SetFutureState(2, 2, true)
	actual := b.GetCurrentState(2, 2)
	if actual != false {
		t.Errorf("Expected false, got %t", actual)
	}
}

func Test_GetCurrentState_AfterSetFutureStateAndTickBelowZero_returnsFalse(t *testing.T) {
	b := NewBoard()
	b.SetFutureState(-1, -1, true)
	b.Tick()

	actual := b.GetCurrentState(-1, -1)

	if actual != false {
		t.Errorf("Expected false, got %t", actual)
	}

}

func Test_GetCurrentState_AfterSetFutureStateAndTickBeyondEdge_returnsFalse(t *testing.T) {
	b := NewBoard()
	b.SetFutureState(b.XMax+1, b.YMax+1, true)
	b.Tick()

	actual := b.GetCurrentState(b.XMax+1, b.YMax+1)

	if actual != false {
		t.Errorf("Expected false, got %t", actual)
	}

}

type Point struct {
	X int
	Y int
}

// Positions are numbered like a phone keypad, with the x, y position at 5 and 1 in the upper left.
func position(x int, y int, position int) Point {
	p := new(Point)
	if position < 1 || position > 9 {
		return *p
	}

	switch position {
	case 1:
		p.X = x - 1
		p.Y = y - 1
	case 2:
		p.X = x
		p.Y = y - 1
	case 3:
		p.X = x + 1
		p.Y = y - 1
	case 4:
		p.X = x - 1
		p.Y = y
	case 5:
		p.X = x
		p.Y = y
	case 6:
		p.X = x + 1
		p.Y = y
	case 7:
		p.X = x - 1
		p.Y = y + 1
	case 8:
		p.X = x
		p.Y = y + 1
	case 9:
		p.X = x + 1
		p.Y = y + 1
	}

	return *p
}

func populateBoard(b *Board, x int, y int, livePositions []int) {
	for _, pos := range livePositions {
		p := position(x, y, pos)
		b.SetFutureState(p.X, p.Y, true)
	}
	b.Tick()
}

func runBoardTest(b *Board, x int, y int, cases map[int][]int, t *testing.T) {
	for expected, positions := range cases {
		populateBoard(b, x, y, positions)
		actual := b.Neighbors(x, y)
		if actual != expected {
			t.Errorf("Expected %d, received %d for %v\n%t %t %t\n%t %t %t\n%t %t %t", expected, actual, positions, b.GetCurrentState(x-1, y-1), b.GetCurrentState(x, y-1), b.GetCurrentState(x+1, y-1), b.GetCurrentState(x-1, y), b.GetCurrentState(x, y), b.GetCurrentState(x+1, y), b.GetCurrentState(x-1, y+1), b.GetCurrentState(x, y+1), b.GetCurrentState(x+1, y+1))
		}
	}
}

func Test_Neighbors(t *testing.T) {
	b := NewBoard()
	cases := map[int][]int{
		0: {},
		1: {1},
		2: {1, 9},
		3: {1, 2, 3},
		5: {1, 2, 3, 4, 6},
		6: {1, 2, 3, 4, 6, 7},
		8: {1, 2, 3, 4, 6, 7, 8, 9},
	}
	runBoardTest(b, 5, 5, cases, t)
}

func Test_NeighborsWithLiveCell(t *testing.T) {
	b := NewBoard()
	cases := map[int][]int{
		0: {5},
		1: {1, 5},
		2: {1, 5, 9},
	}
	runBoardTest(b, 5, 5, cases, t)
}

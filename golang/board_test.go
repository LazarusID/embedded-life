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

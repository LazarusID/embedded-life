package life

import "testing"

func Test_RulesForCurrentlyAlive(t *testing.T) {

	cases := map[int]bool{
		0: false,
		1: false,
		2: true,
		3: true,
		4: false,
		5: false,
		6: false,
		7: false,
		8: false,
	}
	RunCases(cases, true, t)
}

func Test_RulesForCurrentlyDead(t *testing.T) {

	cases := map[int]bool{
		0: false,
		1: false,
		2: false,
		3: true,
		4: false,
		5: false,
		6: false,
		7: false,
		8: false,
	}
	RunCases(cases, false, t)
}

func RunCases(cases map[int]bool, currentlyAlive bool, t *testing.T) {
	for neighbors, expected := range cases {
		actual := isAlive(neighbors, currentlyAlive)
		if actual != expected {
			t.Errorf("Expected %t for %d neighbors, but got %t", expected, neighbors, actual)
		}
	}
}

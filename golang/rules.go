package life

func isAlive(neighbors int, currentlyAlive bool) bool {
	if currentlyAlive {
		switch neighbors {
		case 2, 3:
			return true
		}
	} else {
		if neighbors == 3 {
			return true
		}
	}
	return false
}

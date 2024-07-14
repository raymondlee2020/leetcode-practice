type Robot struct {
	ID        int
	Position  int
	Health    int
	Direction string
}

func survivedRobotsHealths(positions []int, healths []int, directions string) []int {
	ret, n, robots, headr := make([]int, 0), len(positions), make([]*Robot, 0), make([]*Robot, 0)
	for i := range n {
		robots = append(robots, &Robot{i, positions[i], healths[i], string(directions[i])})
	}
	sort.Slice(robots, func(i, j int) bool {
		return robots[i].Position < robots[j].Position
	})
	for _, robot := range robots {
		if robot.Direction == "R" {
			headr = append(headr, robot)
		} else {
			for len(headr) > 0 {
				tmp := headr[len(headr)-1]
				if tmp.Health > robot.Health {
					tmp.Health--
					robot.Health = 0
					break
				} else if tmp.Health < robot.Health {
					robot.Health--
					tmp.Health = 0
					headr = headr[:len(headr)-1]
				} else {
					robot.Health = 0
					tmp.Health = 0
					headr = headr[:len(headr)-1]
					break
				}
			}
		}
	}
	sort.Slice(robots, func(i, j int) bool {
		return robots[i].ID < robots[j].ID
	})
	for _, robot := range robots {
		if robot.Health > 0 {
			ret = append(ret, robot.Health)
		}
	}
	return ret
}
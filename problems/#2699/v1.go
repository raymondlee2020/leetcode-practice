type Adj struct {
	Node, EdgeIndex int
}

type Item struct {
    Node, Dist int
}

type MinHeap []*Item

func (m MinHeap) Len() int {
	return len(m)
}

func (m MinHeap) Less(i int, j int) bool {
	return m[i].Dist < m[j].Dist
}

func (m MinHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m *MinHeap) Push(x interface{}) {
	*m = append(*m, x.(*Item))
}

func (m *MinHeap) Pop() interface{} {
	old := *m
	n := len(old)
	x := old[n-1]
	*m = old[:n-1]
	return x
}

func modifiedGraphEdges(n int, edges [][]int, source int, destination int, target int) [][]int {
	graph := make([][]Adj, n)
	for i, edge := range edges {
		na, nb := edge[0], edge[1]
		graph[na] = append(graph[na], Adj{nb, i})
		graph[nb] = append(graph[nb], Adj{na, i})
	}
	dist := make([][2]int, n)
	for i := range n {
		if i == source {
            continue
        }
        dist[i] = [2]int{math.MaxInt, math.MaxInt}
	}
    dijkstra := func(diff, run int) {
        pq := &MinHeap{}
        heap.Init(pq)
        heap.Push(pq, &Item{source, 0})
        dist[source][run] = 0
        for len(*pq) > 0 {
            curr := heap.Pop(pq).(*Item)
            if curr.Dist > dist[curr.Node][run] {
                continue
            }
            for _, adj := range graph[curr.Node] {
                weight := edges[adj.EdgeIndex][2]
                if weight == -1 {
                    weight = 1
                }
                if run == 1 && edges[adj.EdgeIndex][2] == -1 {
                    newWeight := diff + dist[adj.Node][0] - dist[curr.Node][1]
                    if newWeight > weight {
                        edges[adj.EdgeIndex][2] = newWeight
                        weight = newWeight
                    }
                }
                if dist[adj.Node][run] > dist[curr.Node][run] + weight {
                    dist[adj.Node][run] = dist[curr.Node][run] + weight
                    heap.Push(pq, &Item{adj.Node, dist[adj.Node][run]})
                }
            }
        }
    }
	dijkstra(0, 0)
	diff := target - dist[destination][0]
	if diff < 0 {
		return [][]int{}
	}
	dijkstra(diff, 1)
	if dist[destination][1] < target {
		return [][]int{}
	}
	for i := range edges {
		if edges[i][2] == -1 {
		    edges[i][2] = 1
		}
	}
	return edges
}

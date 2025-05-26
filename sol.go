package main

import (
	"sort"
)

func checkValidCuts(n int, rectangles [][]int) bool {
    merged := mergeInterval(rectangles,true)
    if(len(merged)>=3) {return true}
	merged = mergeInterval(rectangles,false)
	return len(merged)>=3
}

func mergeInterval(rectangles [][]int,v bool ) [][]int{
    intervals := make([][]int,0)
    for _,r := range rectangles{
        intervals = append(intervals,if v {[]int{r[1],r[3]}} else {[]int{r[0],r[2]}})
    }
	sort.Slice(intervals,func(i,j int)bool{
		return intervals[i][0] < intervals[j][0]
	})
	merged := make([][]int,0)
	cur := intervals[0]
	for _,i := range intervals{
		if i[0] < cur[1]{
			cur[1] = max(cur[1],i[1])
		}else{
			merged = append(merged,cur)
			cur = i
		}
	}
	return merged
}
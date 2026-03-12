class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        def bfs(start: Tuple[int, int], end: Tuple[int, int]) -> bool:
            if not blocked:
                return True
            block_set = set(map(tuple, blocked))
            max_steps = len(blocked) * (len(blocked) - 1) // 2
            queue = [start]
            visited = set([start])
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            while queue and len(visited) <= max_steps:
                x, y = queue.pop(0)
                if (x, y) == end:
                    return True
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < 1_000_000 and 0 <= ny < 1_000_000 and (nx, ny) not in block_set and (nx, ny) not in visited:
                        visited.add((nx, ny))
                        queue.append((nx, ny))
            return len(visited) > max_steps

        start, end = tuple(source), tuple(target)
        return bfs(start, end) and bfs(end, start)
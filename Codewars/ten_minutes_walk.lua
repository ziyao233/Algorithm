local is_valid_walk = function(walk)
	if #walk ~= 10
	then
		return false;
	end

	local x,y = 0,0;
	local convertTable = {
				n = {
					y = 1,
					x = 0,
				    },
				w = {
					y = 0,
					x = -1,
				    },
				s = {
					y = -1,
					x = 0,
				    },
				e = {
					y = 0,
					x = 1,
				    },
			     };
	for _,dir in ipairs(walk)
	do
		local delta = convertTable[dir];
		x,y = x + delta.x,y + delta.y;
	end
	return true;
end

return {
	is_valid_walk = is_valid_walk,
       };

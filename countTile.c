/**
 *Original version of countTile, improved version will be update within a week
 * 23/01/2016
 *
 *
 * sideNeed(room, tile) calculates the number of the tile needs when
 * we only consider one side(width or height) for room
 */
int sideNeed(int const room, int const tile){
  if(room % tile == 0){ // to see is integer or not
    return (room / tile);
  } else {
    return ((room / tile) + 1);  // one more tile needed as cannot use rest
  }
}

/*  
 * totalNeed(rCount, tCount, r, t) calculates the total tile need for
 * the room at the side rCount and tCount, r and t are the sides that 
 * will not count in this situation, for example: we want width of t
 * to fit the height of r, the widthT is tCount, rCount is similar
 */

int totalNeed(int const rCount, int const tCount, int const r, int const t){
  int const countSide = sideNeed(rCount, tCount); 
  int const unCountSide = sideNeed(r, t);
  int const need = countSide * unCountSide;
  return need;
}
 
/**  
 * min_tiles(tW, tH, rW, rH) calculates the minimum number of tiles 
 * with wideth tW, height tH, to lay the room with width rW, height rH,
 * the tiles will only be in one direction, either potrait or landscape.
 * requires: tW, tH, rW and rH > 0
 */

int min_tiles(int const tW, int const tH, int const rW, int const rH){
  int const tWidRWid = totalNeed(rW, tW, rH, tH);
  int const tWidRHei = totalNeed(rH, tW, rW, tH);
  
  if(tWidRWid < tWidRHei){
    return tWidRWid;
  } else {
    return tWidRHei;
  }
}

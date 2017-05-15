type token =
  | Circle
  | Cross
  | Empty;

type playerState =
  | CirclePlayer
  | CrossPlayer;

type colIdx =
  | C1
  | C2
  | C3;

type rowIdx =
  | R1
  | R2
  | R3;

type row = (token, token, token);

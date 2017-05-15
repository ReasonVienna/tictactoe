open Game;

let namespace = "reason-react-tictactoe";

module Top = {
  module TicTacToe = {
    include ReactRe.Component.Stateful;
    let name = "TicTacToe";
    type props = unit;
    type state = {rows: (row, row, row), player: playerState};
    let getInitialState _ => {
      rows: ((Empty, Empty, Empty), (Empty, Empty, Empty), (Empty, Empty, Empty)),
      player: CirclePlayer
    };
    let playerToken player =>
      switch player {
      | CirclePlayer => Circle
      | CrossPlayer => Cross
      };
    let switchPlayer (current: playerState) =>
      switch current {
      | CirclePlayer => CrossPlayer
      | CrossPlayer => CirclePlayer
      };
    let isEmptySquare (square: token) =>
      switch square {
      | Empty => true
      | _ => false
      };
    let updateColumn row column value => {
      let (c1, c2, c3) = row;
      switch column {
      | C1 => isEmptySquare c1 ? (value, c2, c3) : row
      | C2 => isEmptySquare c2 ? (c1, value, c3) : row
      | C3 => isEmptySquare c3 ? (c1, c2, value) : row
      }
    };
    let updateRow rows row column value => {
      let (r1, r2, r3) = rows;
      switch row {
      | R1 =>
        let r = updateColumn r1 column value;
        (r, r2, r3)
      | R2 =>
        let r = updateColumn r2 column value;
        (r1, r, r3)
      | R3 =>
        let r = updateColumn r3 column value;
        (r1, r2, r)
      }
    };
    let playTurn {state} (selection: (rowIdx, colIdx)) => {
      let {rows, player} = state;
      let (row, column) = selection;
      Some {
        rows: updateRow rows row column (playerToken player),
        player: switchPlayer state.player
      }
    };
    let render {state, updater} =>
      <div className="game">
        <div className="game-board">
          <Board rows=state.rows handleSquareClick=(updater playTurn) />
        </div>
        <div className="game-info"> <div /> <ol /> </div>
      </div>;
  };
  include ReactRe.CreateComponent TicTacToe;
  let createElement = wrapProps ();
};

ReactDOMRe.renderToElementWithClassName <Top /> "tictactoe";

const path = require('path');

module.exports = {
  entry: {
    tictactoe: './lib/js/src/tictactoe.js',
  },
  output: {
    path: path.join(__dirname, 'bundledOutputs'),
    filename: '[name].js',
  },
};

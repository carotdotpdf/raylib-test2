#include "Tetrominoes.h"

Tetromino::Tetromino(const bool* shape_in, int dimension_in, Color color_in, const Board& board_in)
    : boardPos(board_in.GetWidth() / 2 - dimension_in / 2, 0),  // Initialize boardPos first (order in the header)
      currentRotation(Rotation::UP),                           // Initialize currentRotation second
      shape(shape_in),                                         // Initialize shape third
      dimension(dimension_in),                                 // Initialize dimension fourth
      color(color_in),                                         // Initialize color fifth
      board(board_in)                                          // Initialize board last
{
}


void Tetromino::RotateClockwise()
{
    currentRotation = Rotation((int(currentRotation) + 1) % 4);
}

void Tetromino::RotateCounterClockwise()
{
    if (currentRotation == Rotation::UP)
    {
        currentRotation = Rotation::LEFT;
    }
    else
    {
        currentRotation = Rotation(int(currentRotation) - 1);
    }
}

void Tetromino::Draw() const
{
    for (int y = 0; y < dimension; ++y)
    {
        for (int x = 0; x < dimension; ++x)
        {
            bool cell = false;
            switch (currentRotation)
            {
            case Tetromino::Rotation::UP:
                cell = shape[y * dimension + x];
                break;
            case Tetromino::Rotation::RIGHT:
                cell = shape[(dimension - 1 - y) + x * dimension];  // Corrected rotation formula
                break;
            case Tetromino::Rotation::DOWN:
                cell = shape[(dimension - 1 - x) + (dimension - 1 - y) * dimension];  // Corrected rotation formula
                break;
            case Tetromino::Rotation::LEFT:
                cell = shape[y + (dimension - 1 - x) * dimension];  // Corrected rotation formula
                break;
            default:
                break;
            }

            if (cell)
            {
                board.DrawCell(boardPos + Vec2<int>{x, y}, color);
            }
        }
    }
}

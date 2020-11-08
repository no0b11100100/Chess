#include "chess.h"
#include <iostream>

Chess::Chess()
    : m_board(Board::instance()),
      m_players{Player{Color::White}, Player{Color::Black}}
{}

void Chess::MakeMove(Coordinate From, Coordinate To)
{
    const Cell& cell = m_board.GetCell(From);
    if(cell.figure->CheckMove(To) && m_board.VerificationMove(From, To))
    {
        cell.figure->UpdateCoordinate(To);
        m_board.UpdateBoard(From, To);
    }

    m_board.DrawBoard();
}

void Chess::run()
{
    MakeMove(Coordinate(1, 'a'), Coordinate(2, 'a'));
    MakeMove(Coordinate(2, 'a'), Coordinate(1, 'a'));
}

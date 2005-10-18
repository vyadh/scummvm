/* ScummVM - Scumm Interpreter
 * Copyright (C) 2001-2005 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $Header$
 *
 */

#include "common/stdafx.h"
#include "ItemAction.h"

namespace CEGUI {

	ItemAction::ItemAction(WORD reference, GUI::ActionType action) :
	PanelItem(reference) {
		_action = action;
		if (!GUI::Actions::Instance()->isEnabled(_action))
			_visible = false;
	}


	ItemAction::~ItemAction() {
	}

	bool ItemAction::action(int x, int y, bool pushed) {

		if (checkInside(x, y) && _visible && pushed) {
			GUI::Actions::Instance()->perform(_action);
			return true;
		}
		else
			return false;
	}
}

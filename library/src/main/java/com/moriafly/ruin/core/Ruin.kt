/**
 * Copyright (C) 2021 Moriafly
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

package com.moriafly.ruin.core

object Ruin: RuinInterface {

    override fun existBlackClass(): Boolean = try {
        ClassBlacklist.blacklist.forEach { className ->
            Class.forName(className)
        }
        false
    } catch (e: ClassNotFoundException) {
        true
    }

    override fun existXposed(): Boolean = checkXposed()

    private external fun checkXposed(): Boolean
}
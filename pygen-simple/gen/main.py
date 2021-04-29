import pathlib

import click


CPP_CONTENT = """
#include <iostream>
#include "bsys.hpp"

void bsys::bsys::say_hello() {{
    std::cout << "Hello {name}" << std::endl;
}}
"""


@click.group()
def generate():
    """Generate cpp files."""
    pass


@generate.command()
@click.argument("where", type=click.Path(dir_okay=False, writable=True, allow_dash=True))
@click.argument("name", type=str)
def hello(where, name):
    where = pathlib.Path(where).expanduser().absolute()
    where.parent.mkdir(parents=True, exist_ok=True)
    print(f"writing to {where}")
    where.write_text(CPP_CONTENT.format(name=name))
    print("...  ok" if where.exists() else "...  failed")


if __name__ == "__main__":
    generate()

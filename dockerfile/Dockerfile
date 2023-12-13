FROM emscripten/emsdk
WORKDIR /app

RUN apt install -y curl gcc make build-essential
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
RUN curl https://wasmtime.dev/install.sh -sSf | bash
ENV PATH="/root/.cargo/bin:${PATH}"

RUN cargo install wasm-pack